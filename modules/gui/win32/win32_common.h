/*****************************************************************************
 * win32_common.h: private win32 interface description
 *****************************************************************************
 * Copyright (C) 2002 VideoLAN
 *
 * Authors: Olivier Teuliere <ipkiss@via.ecp.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
 *****************************************************************************/

#include "disc.h"
#include "mainframe.h"
#include "menu.h"
#include "messages.h"
#include "network.h"
#include "playlist.h"
#include "preferences.h"

/*****************************************************************************
 * The TrackBar is graduated from 0 to SLIDER_MAX_VALUE.
 * SLIDER_MAX_VALUE is set to the higher acceptable value (2^31 - 1), in order
 * to obtain the best precision in date calculation
 *****************************************************************************/
#define SLIDER_MAX_VALUE 2147483647

/*****************************************************************************
 * intf_sys_t: description and status of Win32 interface
 *****************************************************************************/
struct intf_sys_t
{
    /* special actions */
    vlc_bool_t          b_playing;
    vlc_bool_t          b_popup_changed;             /* display popup menu ? */
    vlc_bool_t          b_slider_free;                      /* slider status */

    /* menus handlers */
    vlc_bool_t          b_aout_update;         /* do we need to update menus
                                                   related with audio output */
    vlc_bool_t          b_vout_update;         /* do we need to update menus
                                                   related with video output */
    vlc_bool_t          b_program_update;   /* do we need to update programs
                                                                        menu */
    vlc_bool_t          b_title_update;  /* do we need to update title menus */
    vlc_bool_t          b_chapter_update;    /* do we need to update chapter
                                                                       menus */
    vlc_bool_t          b_audio_update;  /* do we need to update audio menus */
    vlc_bool_t          b_spu_update;      /* do we need to update spu menus */

    /* windows and widgets */
    TMainFrameDlg     * p_window;                             /* main window */
    TPlaylistDlg      * p_playwin;                               /* playlist */
    TPopupMenu        * p_popup;                               /* popup menu */
    TDiscDlg          * p_disc;                     /* disc selection window */
    TNetworkDlg       * p_network;                  /* network stream window */
    TPreferencesDlg   * p_preferences;                 /* preferences window */
    TMenusGen         * p_menus;               /* object for menu generation */

    /* The slider */
    off_t               OldValue;                          /* previous value */

    /* The messages window */
    TMessagesDlg      * p_messages;                       /* messages window */
    msg_subscription_t* p_sub;                  /* message bank subscription */

    /* Playlist management */
    int                 i_playing;                 /* playlist selected item */
    vlc_bool_t          b_play_when_adding;

    /* The window labels for DVD mode */
    TLabel            * p_label_title;
    TLabel            * p_label_chapter;
    int                 i_part;                           /* current chapter */

    /* The input thread */
    input_thread_t    * p_input;
};

