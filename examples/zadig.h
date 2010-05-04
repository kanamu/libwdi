/*
 * List and install driver for USB devices (GUI version)
 * Copyright (c) 2010 Pete Batard <pbatard@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#pragma once

#if !defined(bool)
#define bool BOOL
#endif
#if !defined(true)
#define true TRUE
#endif
#if !defined(false)
#define false FALSE
#endif

#define STR_BUFFER_SIZE             256
#define NOTIFICATION_DELAY          500
#define DEFAULT_DIR                 "C:\\usb_driver"

// WM_APP is not sent on focus, unlike WM_USER
#define UM_REFRESH_LIST             WM_APP
#define UM_DEVICE_EVENT            (WM_APP+1)
#define UM_LOGGER_EVENT            (WM_APP+2)

#define safe_free(p) do {if (p != NULL) {free(p); p = NULL;}} while(0)
#define safe_strncpy(dst, dst_max, src, count) strncpy(dst, src, min(count, dst_max - 1))
#define safe_strcpy(dst, dst_max, src) safe_strncpy(dst, dst_max, src, strlen(src)+1)
#define safe_strncat(dst, dst_max, src, count) strncat(dst, src, min(count, dst_max - strlen(dst) - 1))
#define safe_strcat(dst, dst_max, src) safe_strncat(dst, dst_max, src, strlen(src)+1)
#define safe_strcmp(str1, str2) strcmp(((str1==NULL)?"<NULL>":str1), ((str2==NULL)?"<NULL>":str2))
#define safe_strncmp(str1, str2, count) strncmp(((str1==NULL)?"<NULL>":str1), ((str2==NULL)?"<NULL>":str2), count)
#define safe_closehandle(h) do {if (h != INVALID_HANDLE_VALUE) {CloseHandle(h); h = INVALID_HANDLE_VALUE;}} while(0)
#define safe_sprintf _snprintf
#define safe_strdup _strdup

#if defined(_MSC_VER)
#define safe_vsnprintf vsprintf_s
#else
#define safe_vsnprintf vsnprintf
#endif

/*
 * Shared prototypes
 */
#define dprintf(...) w_printf(__VA_ARGS__)
void w_printf(const char *format, ...);
void browse_for_folder(void);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

/*
 * Globals
 */
extern HINSTANCE main_instance;
extern HWND hDeviceList;
extern HWND hDriver;
extern HWND hMain;
extern HMENU hMenu;
extern char path[MAX_PATH];
