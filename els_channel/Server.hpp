#pragma once

#include "boost/asio.hpp"
#include "boost/shared_ptr.hpp"
#include "Connection.hpp"
#include "GameConnection.hpp"
#include "World.hpp"
#include <map>

namespace els {
	
	typedef boost::shared_ptr<Connection> sessionPtr;
	typedef boost::shared_ptr<GameConnection> gameSessPtr;
	
	class Server : boost::noncopyable {
		public:
			boost::asio::io_service iosvc;
			boost::asio::ip::udp::socket udpsocket;
			boost::asio::ip::udp::endpoint udp_remote_endpoint;
			boost::asio::ip::tcp::acceptor channel_acceptor; // 9300
			boost::asio::ip::tcp::acceptor game_acceptor; // 9301
			boost::shared_array<unsigned char> udpRecvBuffer;
			Server(short channelPort, short gamePort)
				: channel_acceptor(iosvc, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), channelPort)),
				game_acceptor(iosvc, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), gamePort)),
				udpsocket(iosvc, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 9101)) {}
			~Server() {};
			// tcp
			void startChannelAccept();
			void handleChannelAccept(sessionPtr session, const boost::system::error_code& error);
			void startGameAccept();
			void handleGameAccept(gameSessPtr session, const boost::system::error_code& error);
			// udp
			void startReceive();
			void handleReceive(const boost::system::error_code& error, size_t);
			void udpSend(unsigned char* packet, int size);
			void handleSend(const boost::system::error_code& error, size_t);
			// end udp
			void init();

	};

}