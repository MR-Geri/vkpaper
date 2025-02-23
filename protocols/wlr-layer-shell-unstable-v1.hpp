// Generated with hyprwayland-scanner 0.4.4. Made with vaxry's keyboard and ❤️.
// wlr_layer_shell_v1_unstable_v1

/*
 This protocol's authors' copyright notice is:


    Copyright © 2017 Drew DeVault

    Permission to use, copy, modify, distribute, and sell this
    software and its documentation for any purpose is hereby granted
    without fee, provided that the above copyright notice appear in
    all copies and that both that copyright notice and this permission
    notice appear in supporting documentation, and that the name of
    the copyright holders not be used in advertising or publicity
    pertaining to distribution of the software without specific,
    written prior permission.  The copyright holders make no
    representations about the suitability of this software for any
    purpose.  It is provided "as is" without express or implied
    warranty.

    THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
    SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
    FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
    SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
    AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
    ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
    THIS SOFTWARE.
  
*/

#pragma once

#include <functional>
#include <cstdint>
#include <string>
#include <wayland-client.h>

#define F std::function

struct wl_proxy;

enum zwlrLayerShellV1Error : uint32_t {
    ZWLR_LAYER_SHELL_V1_ERROR_ROLE = 0,
    ZWLR_LAYER_SHELL_V1_ERROR_INVALID_LAYER = 1,
    ZWLR_LAYER_SHELL_V1_ERROR_ALREADY_CONSTRUCTED = 2,
};

enum zwlrLayerShellV1Layer : uint32_t {
    ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND = 0,
    ZWLR_LAYER_SHELL_V1_LAYER_BOTTOM = 1,
    ZWLR_LAYER_SHELL_V1_LAYER_TOP = 2,
    ZWLR_LAYER_SHELL_V1_LAYER_OVERLAY = 3,
};

enum zwlrLayerSurfaceV1Error : uint32_t {
    ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SURFACE_STATE = 0,
    ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SIZE = 1,
    ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_ANCHOR = 2,
};

enum zwlrLayerSurfaceV1Anchor : uint32_t {
    ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP = 1,
    ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM = 2,
    ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT = 4,
    ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT = 8,
};


class CCZwlrLayerShellV1;
class CCZwlrLayerSurfaceV1;
class CCWlSurface;
class CCWlOutput;
class CCZwlrLayerSurfaceV1;
class CCXdgPopup;

#ifndef HYPRWAYLAND_SCANNER_NO_INTERFACES
extern const wl_interface zwlr_layer_shell_v1_interface;
extern const wl_interface zwlr_layer_surface_v1_interface;

#endif


class CCZwlrLayerShellV1 {
  public:
    CCZwlrLayerShellV1(wl_proxy*);
    ~CCZwlrLayerShellV1();


    // set the data for this resource
    void setData(void* data) {{
        pData = data;
    }}

    // get the data for this resource
    void* data() {{
        return pData;
    }}

    // get the raw wl_resource (wl_proxy) ptr
    wl_proxy* resource() {{
        return pResource;
    }}

    // get the raw wl_proxy ptr
    wl_proxy* proxy() {{
        return pResource;
    }}

    // get the resource version
    int version() {{
        return wl_proxy_get_version(pResource);
    }}
            
    // --------------- Requests --------------- //


    // --------------- Events --------------- //

    wl_proxy* sendGetLayerSurface(wl_proxy*, wl_proxy*, zwlrLayerShellV1Layer, const char*);

  private:
    struct {
    } requests;

    wl_proxy* pResource = nullptr;

    bool destroyed = false;

    void* pData = nullptr;
};



class CCZwlrLayerSurfaceV1 {
  public:
    CCZwlrLayerSurfaceV1(wl_proxy*);
    ~CCZwlrLayerSurfaceV1();


    // set the data for this resource
    void setData(void* data) {{
        pData = data;
    }}

    // get the data for this resource
    void* data() {{
        return pData;
    }}

    // get the raw wl_resource (wl_proxy) ptr
    wl_proxy* resource() {{
        return pResource;
    }}

    // get the raw wl_proxy ptr
    wl_proxy* proxy() {{
        return pResource;
    }}

    // get the resource version
    int version() {{
        return wl_proxy_get_version(pResource);
    }}
            
    // --------------- Requests --------------- //

    void setConfigure(F<void(CCZwlrLayerSurfaceV1*, uint32_t, uint32_t, uint32_t)> handler);
    void setClosed(F<void(CCZwlrLayerSurfaceV1*)> handler);

    // --------------- Events --------------- //

    void sendSetSize(uint32_t, uint32_t);
    void sendSetAnchor(zwlrLayerSurfaceV1Anchor);
    void sendSetExclusiveZone(int32_t);
    void sendSetMargin(int32_t, int32_t, int32_t, int32_t);
    void sendSetKeyboardInteractivity(uint32_t);
    void sendGetPopup(wl_proxy*);
    void sendAckConfigure(uint32_t);
    void sendDestroy();

  private:
    struct {
        F<void(CCZwlrLayerSurfaceV1*, uint32_t, uint32_t, uint32_t)> configure;
        F<void(CCZwlrLayerSurfaceV1*)> closed;
    } requests;

    wl_proxy* pResource = nullptr;

    bool destroyed = false;

    void* pData = nullptr;
};



#undef F
