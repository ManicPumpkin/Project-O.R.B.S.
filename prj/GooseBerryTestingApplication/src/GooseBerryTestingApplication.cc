/**
@file	GooseBerryTestingApplication.cc
@brief	Includes main program
@author	drubner
@date	2013-12-17
**/
//==================================================================
//	INCLUDE
//==================================================================
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>

#include "..\..\Log\inc\Log.h"
#include "..\..\GooseBerry\inc\GooseBerry.h"

//==================================================================
//	NAMESPACE
//==================================================================
using namespace std;

//==================================================================
//	GLOBALS
//==================================================================
GB_OpenGL	g_open_gl;
bool		g_render_init = FALSE;

//==================================================================
//	PREDEFINITION
//==================================================================
GB_Enum::gbResult Initialize();
GB_Enum::gbResult Exit();
GB_Enum::gbResult Load();
GB_Enum::gbResult Unload();
GB_Enum::gbResult Show(HWND hwnd);
GB_Enum::gbResult Run();
GB_Enum::gbResult Render(float time);

//==================================================================
//	MAIN
//==================================================================
int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE h_prev_instance, PSTR cmd_line, int cmd_show)
{
	GB_Var::g_hinstance				= hinstance;
	GB_Var::g_hwnd					= NULL;
	GB_Var::g_wnd_title				= "GooseBerryTestApplication";
	GB_Var::g_wnd_name				= "GooseBerryTestApplication";
	GB_Var::g_wnd_width				= 800;
	GB_Var::g_wnd_height			= 600;
	GB_Var::g_wnd_x					= 0;
	GB_Var::g_wnd_y					= 0;
	GB_Var::g_bits_color			= 32;
	GB_Var::g_bits_depth			= 32;
	GB_Var::g_bits_alpha			= 32;
	GB_Var::g_fullscreen			= FALSE;
	GB_Var::g_active				= TRUE;

	Log::getInstance()->set_file_path_and_name(string("log"), string("log.html"));
	Log::getInstance()->debug_mode_ = true;
	LOG_DEBUG("GooseBerryTestingApplication started");
	LOG_DEBUG("Log system initialized succesfully");

	//	Start code here
	try
	{
		GB_Func::Initialize();

		//	initialize, show, run, exit
		Initialize();
		Show(GB_Var::g_hwnd);
		Run();
		Exit();

		if(GB_Func::Exit())
			throw GB_Exception(ERR_GB_EXIT_STR, ERR_GB_EXIT_ID);
	}
	catch (const GB_Exception &exception)
	{
		LOG_ERROR(exception.GetStr(), exception.GetId());
		GB_MSGBOXERR(exception.GetStr(), exception.GetId());
	}

	LOG_DEBUG("GooseBerryTestingApplication finished");
	getchar();

	delete Log::getInstance();
	getchar();

	return 0;
}

GB_Enum::gbResult Initialize()
{
	LOG_INFO("Initialize application");
	g_open_gl.StartWnd();

	if (Load())
		throw GB_Exception(ERR_G_LOAD_STR, ERR_G_LOAD_ID);

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Exit()
{
	LOG_INFO("Exit application");

	if (Unload())
		throw GB_Exception(ERR_G_EXIT_STR, ERR_G_EXIT_ID);

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Load()
{
	LOG_DEBUG("Load application");

	//	load some stuff here ...

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Unload()
{
	LOG_DEBUG("Unload application");

	//	unload some stuff here ...

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Show(HWND hwnd)
{
	LOG_DEBUG("Showing window");
	ShowWindow(hwnd, SW_SHOW);
	SetForegroundWindow(hwnd);
	SetFocus(hwnd);
	
	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Run()
{
	LOG_INFO("Run application");

	if (GB_Func::MessageLoop(&::Render))
		LOG_ERROR(ERR_GB_MSGL_STR, ERR_GB_MSGL_ID);

	return GB_Enum::GB_OK;
}

GB_Enum::gbResult Render(float time)
{
	if (!g_render_init)
	{
		g_render_init = TRUE;
		LOG_DEBUG("Start render process");
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	return GB_Enum::GB_OK;
}