/*
 * Copyright (c) 2022 Jiri Svoboda
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - The name of the author may not be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/** @addtogroup display
 * @{
 */
/**
 * @file Display server WM client type
 */

#ifndef TYPES_DISPLAY_WMCLIENT_H
#define TYPES_DISPLAY_WMCLIENT_H

#include <adt/list.h>
#include <wndmgt.h>

/** Display server WM client callbacks */
typedef struct {
	void (*ev_pending)(void *);
} ds_wmclient_cb_t;

/** Display server WM client */
typedef struct ds_wmclient {
	/** Parent display */
	struct ds_display *display;
	/** Callbacks */
	ds_wmclient_cb_t *cb;
	/** Callback argument */
	void *cb_arg;
	/** Link to @c display->wmclients */
	link_t lwmclients;
	/** Event queue (of ds_window_ev_t) */
	list_t events;
} ds_wmclient_t;

/** WM client event queue entry */
typedef struct {
	/** Link to event queue */
	link_t levents;
	/** WM client to which the event is delivered */
	ds_wmclient_t *wmclient;
	/** Event */
	wndmgt_ev_t event;
} ds_wmclient_ev_t;

#endif

/** @}
 */
