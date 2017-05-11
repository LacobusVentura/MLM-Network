/*!
	\file Exception.hpp
	\brief Exception Control Interface
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#ifndef __EXCEPTION_HPP__
#define __EXCEPTION_HPP__

#include <string>
#include <exception>
#include <sstream>
#include <iostream>

#define throwex( _ex )  throw MLM::create_exception_tracer( _ex, __FUNCTION__, __FILE__, __LINE__ )

namespace MLM
{
	class Exception : public std::exception
	{
		public:

			Exception( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~Exception( void ) throw() {};

			virtual const std::string& msg( void ) const { return m_msg; }
			virtual const char * what( void ) const throw() { return m_msg.c_str(); }

		protected:

			std::string m_msg;
	};


	template<class EX>
	class ExceptionTracer : public EX
	{
		public:

			ExceptionTracer( const EX& e, const std::string& file, const std::string& func, unsigned int line )
			{

				#ifdef _DEBUG
				std::ostringstream oss;
				oss << e.msg() << " (" << func << " @ " << file << ":" << line << ")";
				m_tracer_msg = oss.str();
				#else
				m_tracer_msg = e.msg();
				#endif
			}

			virtual ~ExceptionTracer( void ) throw() {}

			virtual const std::string& msg( void ) const { return m_tracer_msg; }
			virtual const char * what( void ) const throw() { return m_tracer_msg.c_str(); }

		private:

			std::string m_tracer_msg;
	};


	template<class EX>
	ExceptionTracer<EX> create_exception_tracer( const EX& e, const std::string& func, const std::string& file, unsigned int line )
	{
		return ExceptionTracer<EX>( e, func, file, line );
	};


	class IOException : public Exception
	{
		public:
			IOException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~IOException( void ) throw() {};
	};


	class OverFlowException : public Exception
	{
		public:
			OverFlowException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~OverFlowException( void ) throw() {};
	};


	class UnderFlowException : public Exception
	{
		public:
			UnderFlowException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~UnderFlowException( void ) throw() {};
	};


	class RunTimeException : public Exception
	{
		public:
			RunTimeException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~RunTimeException( void ) throw() {};
	};


	class NullPointerException : public RunTimeException
	{
		public:
			NullPointerException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~NullPointerException( void ) throw() {};
	};


	class IllegalArgumentsException : public RunTimeException
	{
		public:
			IllegalArgumentsException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~IllegalArgumentsException( void ) throw() {};
	};


	class ArithmeticException : public RunTimeException
	{
		public:
			ArithmeticException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~ArithmeticException( void ) throw() {};
	};


	class IndexOutOfBoundsException : public RunTimeException
	{
		public:
			IndexOutOfBoundsException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~IndexOutOfBoundsException( void ) throw() {};
	};


	class FileIOException : public IOException
	{
		public:
			FileIOException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~FileIOException( void ) throw() {};
	};


	class FileNotFoundException : public FileIOException
	{
		public:
			FileNotFoundException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~FileNotFoundException( void ) throw() {};
	};


	class FileWriteException : public FileIOException
	{
		public:
			FileWriteException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~FileWriteException( void ) throw() {};
	};


	class FileReadException : public FileIOException
	{
		public:
			FileReadException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~FileReadException( void ) throw() {};
	};


	class ParserException : public Exception
	{
		public:
			ParserException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~ParserException( void ) throw() {};
	};


	class JSONParserException : public ParserException
	{
		public:
			JSONParserException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~JSONParserException( void ) throw() {};
	};


	class DataBaseException : public Exception
	{
		public:
			DataBaseException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~DataBaseException( void ) throw() {};
	};


	class ConnectionDataBaseException : public DataBaseException
	{
		public:
			ConnectionDataBaseException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~ConnectionDataBaseException( void ) throw() {};
	};


	class QueryDataBaseException : public DataBaseException
	{
		public:
			QueryDataBaseException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~QueryDataBaseException( void ) throw() {};
	};


	class InvalidSyntaxException : public RunTimeException
	{
		public:
			InvalidSyntaxException( const std::string& msg = "" ) { m_msg = msg; };
			virtual ~InvalidSyntaxException( void ) throw() {};
	};
}

#endif

/* $Id: Exception.hpp 427 2017-05-02 12:18:23Z tiago.ventura $ */
