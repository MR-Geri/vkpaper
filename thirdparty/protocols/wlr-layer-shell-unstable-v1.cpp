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

#define private public
#define HYPRWAYLAND_SCANNER_NO_INTERFACES
#include "wlr-layer-shell-unstable-v1.hpp"
#undef private
#define F std::function

static const wl_interface* dummyTypes[] = { nullptr };

// Reference all other interfaces.
// The reason why this is in snake is to
// be able to cooperate with existing
// wayland_scanner interfaces (they are interop)
extern const wl_interface zwlr_layer_shell_v1_interface;
extern const wl_interface zwlr_layer_surface_v1_interface;
extern const wl_interface wl_surface_interface;
extern const wl_interface wl_output_interface;
extern const wl_interface xdg_popup_interface;

static const void* _CCZwlrLayerShellV1VTable[] = {
};

wl_proxy* CCZwlrLayerShellV1::sendGetLayerSurface(wl_proxy* surface, wl_proxy* output, zwlrLayerShellV1Layer layer, const char* namespace_) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &zwlr_layer_surface_v1_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, surface, output, layer, namespace_);

    return proxy;
}
static const wl_interface* _CZwlrLayerShellV1GetLayerSurfaceTypes[] = {
    &zwlr_layer_surface_v1_interface,
    &wl_surface_interface,
    &wl_output_interface,
    nullptr,
    nullptr,
};

static const wl_message _CZwlrLayerShellV1Requests[] = {
    { "get_layer_surface", "no?ous", _CZwlrLayerShellV1GetLayerSurfaceTypes + 0},
};

const wl_interface zwlr_layer_shell_v1_interface = {
    "zwlr_layer_shell_v1", 1,
    1, _CZwlrLayerShellV1Requests,
    0, nullptr,
};

CCZwlrLayerShellV1::CCZwlrLayerShellV1(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCZwlrLayerShellV1VTable, this);
}

CCZwlrLayerShellV1::~CCZwlrLayerShellV1() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

static void _CZwlrLayerSurfaceV1Configure(void* data, void* resource, uint32_t serial, uint32_t width, uint32_t height) {
    const auto PO = (CCZwlrLayerSurfaceV1*)data;
    if (PO && PO->requests.configure)
        PO->requests.configure(PO, serial, width, height);
}

static void _CZwlrLayerSurfaceV1Closed(void* data, void* resource) {
    const auto PO = (CCZwlrLayerSurfaceV1*)data;
    if (PO && PO->requests.closed)
        PO->requests.closed(PO);
}

static const void* _CCZwlrLayerSurfaceV1VTable[] = {
    (void*)_CZwlrLayerSurfaceV1Configure,
    (void*)_CZwlrLayerSurfaceV1Closed,
};

void CCZwlrLayerSurfaceV1::sendSetSize(uint32_t width, uint32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, width, height);
    proxy;
}

void CCZwlrLayerSurfaceV1::sendSetAnchor(zwlrLayerSurfaceV1Anchor anchor) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, anchor);
    proxy;
}

void CCZwlrLayerSurfaceV1::sendSetExclusiveZone(int32_t zone) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, zone);
    proxy;
}

void CCZwlrLayerSurfaceV1::sendSetMargin(int32_t top, int32_t right, int32_t bottom, int32_t left) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, top, right, bottom, left);
    proxy;
}

void CCZwlrLayerSurfaceV1::sendSetKeyboardInteractivity(uint32_t keyboard_interactivity) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, keyboard_interactivity);
    proxy;
}

void CCZwlrLayerSurfaceV1::sendGetPopup(wl_proxy* popup) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 5, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, popup);
    proxy;
}

void CCZwlrLayerSurfaceV1::sendAckConfigure(uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 6, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, serial);
    proxy;
}

void CCZwlrLayerSurfaceV1::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 7, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CZwlrLayerSurfaceV1SetSizeTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CZwlrLayerSurfaceV1SetAnchorTypes[] = {
    nullptr,
};
static const wl_interface* _CZwlrLayerSurfaceV1SetExclusiveZoneTypes[] = {
    nullptr,
};
static const wl_interface* _CZwlrLayerSurfaceV1SetMarginTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CZwlrLayerSurfaceV1SetKeyboardInteractivityTypes[] = {
    nullptr,
};
static const wl_interface* _CZwlrLayerSurfaceV1GetPopupTypes[] = {
    &xdg_popup_interface,
};
static const wl_interface* _CZwlrLayerSurfaceV1AckConfigureTypes[] = {
    nullptr,
};
static const wl_interface* _CZwlrLayerSurfaceV1ConfigureTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};

static const wl_message _CZwlrLayerSurfaceV1Requests[] = {
    { "set_size", "uu", _CZwlrLayerSurfaceV1SetSizeTypes + 0},
    { "set_anchor", "u", _CZwlrLayerSurfaceV1SetAnchorTypes + 0},
    { "set_exclusive_zone", "i", _CZwlrLayerSurfaceV1SetExclusiveZoneTypes + 0},
    { "set_margin", "iiii", _CZwlrLayerSurfaceV1SetMarginTypes + 0},
    { "set_keyboard_interactivity", "u", _CZwlrLayerSurfaceV1SetKeyboardInteractivityTypes + 0},
    { "get_popup", "o", _CZwlrLayerSurfaceV1GetPopupTypes + 0},
    { "ack_configure", "u", _CZwlrLayerSurfaceV1AckConfigureTypes + 0},
    { "destroy", "", dummyTypes + 0},
};

static const wl_message _CZwlrLayerSurfaceV1Events[] = {
    { "configure", "uuu", _CZwlrLayerSurfaceV1ConfigureTypes + 0},
    { "closed", "", dummyTypes + 0},
};

const wl_interface zwlr_layer_surface_v1_interface = {
    "zwlr_layer_surface_v1", 1,
    8, _CZwlrLayerSurfaceV1Requests,
    2, _CZwlrLayerSurfaceV1Events,
};

CCZwlrLayerSurfaceV1::CCZwlrLayerSurfaceV1(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCZwlrLayerSurfaceV1VTable, this);
}

CCZwlrLayerSurfaceV1::~CCZwlrLayerSurfaceV1() {
    if (!destroyed)
        sendDestroy();
}

void CCZwlrLayerSurfaceV1::setConfigure(F<void(CCZwlrLayerSurfaceV1*, uint32_t, uint32_t, uint32_t)> handler) {
    requests.configure = handler;
}

void CCZwlrLayerSurfaceV1::setClosed(F<void(CCZwlrLayerSurfaceV1*)> handler) {
    requests.closed = handler;
}

#undef F
