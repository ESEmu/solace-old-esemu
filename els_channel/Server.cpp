#include "Server.hpp"
#include "Connection.hpp"
#include "DungeonPacket.hpp"
#include "boost/asio.hpp"
#include "boost/bind.hpp"

namespace els {

	void Server::startChannelAccept() {
		sessionPtr session(new Connection(iosvc));
		channel_acceptor.async_accept(session->getSocket(), boost::bind(&Server::handleChannelAccept, this, session, boost::asio::placeholders::error));
	}

	void Server::handleChannelAccept(sessionPtr session, const boost::system::error_code& error) {
		if (!error) {
			session->start();
			if (World::hasClient(session->getSocket().remote_endpoint().address().to_string())) {
				World::getClient(session->getSocket().remote_endpoint().address().to_string())->first = session.get();
			}
			else {
				World::addClient(session->getSocket().remote_endpoint().address().to_string(), session.get());
			}
			startChannelAccept();
		}
	}

	void Server::startGameAccept() {
		gameSessPtr session(new GameConnection(iosvc));
		game_acceptor.async_accept(session->getSocket(), boost::bind(&Server::handleGameAccept, this, session, boost::asio::placeholders::error));
	}

	void Server::handleGameAccept(gameSessPtr session, const boost::system::error_code& error) {
		if (!error) {
			session->start(); // change this
			if (World::hasClient(session->getSocket().remote_endpoint().address().to_string())) {
				World::getClient(session->getSocket().remote_endpoint().address().to_string())->second = session.get();
			}
			else {
				// second connection without first connection? hacking!
				session->getSocket().close();
			}
			startGameAccept();
		}
	}

	void Server::startReceive() {
		udpRecvBuffer.reset(new unsigned char[17]);
		udpsocket.async_receive_from(boost::asio::buffer(udpRecvBuffer.get(), 17), udp_remote_endpoint, boost::bind(&Server::handleReceive, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

	void Server::handleReceive(const boost::system::error_code& error, size_t) {
		std::cout << error << std::endl;
		if (!error || error == boost::asio::error::message_size) {
			for (int i = 0; i < 17; i++) {
				std::cout << static_cast<int>(udpRecvBuffer[i]) << " ";
			}
			udpRecvBuffer[0]++;
		}
		std::cout << std::endl;
		udpSend(udpRecvBuffer.get(), 17);
		World::getClient(udp_remote_endpoint.address().to_string())->first->sendPacket(DungeonPacket::unknown_0xA0(0x02, 0x02).getPacket());
	}

	void Server::udpSend(unsigned char* packet, int size) {
		std::cout << "UDP SEND:" << std::endl;
		for (int i = 0; i < 17; i++) {
			std::cout << static_cast<int>(packet[i]) << " ";
		}
		std::cout << std::endl;
		udpsocket.async_send_to(boost::asio::buffer(packet, size), udp_remote_endpoint, boost::bind(&Server::handleSend, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

	void Server::handleSend(const boost::system::error_code& error, size_t) {
		std::cout << error << std::endl;
		std::cout << udp_remote_endpoint.address() << std::endl;
		startReceive();
	}


	void Server::init() {
		startChannelAccept();
		startGameAccept();
		startReceive();
		iosvc.run();
	}

}