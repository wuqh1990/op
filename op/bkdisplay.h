#pragma once
#include <boost/interprocess/sync/named_mutex.hpp> 
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/windows_shared_memory.hpp> 
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <exception>
class bkdisplay
{
public:
	bkdisplay();
	~bkdisplay();
	//bind window
	virtual long Bind(HWND hwnd, long flag) = 0;
	//unbind window
	virtual long UnBind() = 0;
	//��ͼ���ļ�
	virtual long capture(const std::wstring& file_name) = 0;
	//��Ϊ���ֽ�ͼ��ʽ�Ĳ��죬�Ƿ�ɹ��жϽϸ��ӣ����ڴ�ʵ����Դ��������ͷţ��������
	//��Դ����
	long bind_init();
	//��Դ�ͷ�
	long bind_release();
	byte* get_data() { 
		return (byte*)_region->get_address(); 
	}

	boost::interprocess::named_mutex* get_mutex() {
		return _pmutex;
	}

	long get_height() {
		return _height;
	}

	long get_width() {
		return _width;
	}
public:
	//���ھ��
	HWND _hwnd;
	//��ַӳ��
	boost::interprocess::mapped_region* _region;
	//���̻�����
	boost::interprocess::named_mutex* _pmutex;

	char _shared_res_name[256];

	char _mutex_name[256];
	//��״̬
	long _bind_state;
	//����
	long _width;
	long _height;
	//�ͻ���ƫ��
	int _client_x, _client_y;

	
};
