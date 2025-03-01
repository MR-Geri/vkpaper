// Generated with hyprwayland-scanner 0.4.4. Made with vaxry's keyboard and ❤️.
// xdg_shell

/*
 This protocol's authors' copyright notice is:


    Copyright © 2008-2013 Kristian Høgsberg
    Copyright © 2013      Rafael Antognolli
    Copyright © 2013      Jasper St. Pierre
    Copyright © 2010-2013 Intel Corporation
    Copyright © 2015-2017 Samsung Electronics Co., Ltd
    Copyright © 2015-2017 Red Hat Inc.

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice (including the next
    paragraph) shall be included in all copies or substantial portions of the
    Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
  
*/

#define private public
#define HYPRWAYLAND_SCANNER_NO_INTERFACES
#include "xdg-shell.hpp"
#undef private
#define F std::function

static const wl_interface* dummyTypes[] = { nullptr };

// Reference all other interfaces.
// The reason why this is in snake is to
// be able to cooperate with existing
// wayland_scanner interfaces (they are interop)
extern const wl_interface xdg_wm_base_interface;
extern const wl_interface xdg_positioner_interface;
extern const wl_interface xdg_surface_interface;
extern const wl_interface xdg_toplevel_interface;
extern const wl_interface xdg_popup_interface;
extern const wl_interface wl_surface_interface;
extern const wl_interface wl_seat_interface;
extern const wl_interface wl_output_interface;

static void _CXdgWmBasePing(void* data, void* resource, uint32_t serial) {
    const auto PO = (CCXdgWmBase*)data;
    if (PO && PO->requests.ping)
        PO->requests.ping(PO, serial);
}

static const void* _CCXdgWmBaseVTable[] = {
    (void*)_CXdgWmBasePing,
};

void CCXdgWmBase::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

wl_proxy* CCXdgWmBase::sendCreatePositioner() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, &xdg_positioner_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

wl_proxy* CCXdgWmBase::sendGetXdgSurface(wl_proxy* surface) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, &xdg_surface_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, surface);

    return proxy;
}

void CCXdgWmBase::sendPong(uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, serial);
    proxy;
}
static const wl_interface* _CXdgWmBaseCreatePositionerTypes[] = {
    &xdg_positioner_interface,
};
static const wl_interface* _CXdgWmBaseGetXdgSurfaceTypes[] = {
    &xdg_surface_interface,
    &wl_surface_interface,
};
static const wl_interface* _CXdgWmBasePongTypes[] = {
    nullptr,
};
static const wl_interface* _CXdgWmBasePingTypes[] = {
    nullptr,
};

static const wl_message _CXdgWmBaseRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "create_positioner", "n", _CXdgWmBaseCreatePositionerTypes + 0},
    { "get_xdg_surface", "no", _CXdgWmBaseGetXdgSurfaceTypes + 0},
    { "pong", "u", _CXdgWmBasePongTypes + 0},
};

static const wl_message _CXdgWmBaseEvents[] = {
    { "ping", "u", _CXdgWmBasePingTypes + 0},
};

const wl_interface xdg_wm_base_interface = {
    "xdg_wm_base", 6,
    4, _CXdgWmBaseRequests,
    1, _CXdgWmBaseEvents,
};

CCXdgWmBase::CCXdgWmBase(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCXdgWmBaseVTable, this);
}

CCXdgWmBase::~CCXdgWmBase() {
    if (!destroyed)
        sendDestroy();
}

void CCXdgWmBase::setPing(F<void(CCXdgWmBase*, uint32_t)> handler) {
    requests.ping = handler;
}

static const void* _CCXdgPositionerVTable[] = {
};

void CCXdgPositioner::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCXdgPositioner::sendSetSize(int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, width, height);
    proxy;
}

void CCXdgPositioner::sendSetAnchorRect(int32_t x, int32_t y, int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y, width, height);
    proxy;
}

void CCXdgPositioner::sendSetAnchor(xdgPositionerAnchor anchor) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, anchor);
    proxy;
}

void CCXdgPositioner::sendSetGravity(xdgPositionerGravity gravity) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, gravity);
    proxy;
}

void CCXdgPositioner::sendSetConstraintAdjustment(xdgPositionerConstraintAdjustment constraint_adjustment) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 5, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, constraint_adjustment);
    proxy;
}

void CCXdgPositioner::sendSetOffset(int32_t x, int32_t y) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 6, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y);
    proxy;
}

void CCXdgPositioner::sendSetReactive() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 7, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCXdgPositioner::sendSetParentSize(int32_t parent_width, int32_t parent_height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 8, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, parent_width, parent_height);
    proxy;
}

void CCXdgPositioner::sendSetParentConfigure(uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 9, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, serial);
    proxy;
}
static const wl_interface* _CXdgPositionerSetSizeTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgPositionerSetAnchorRectTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgPositionerSetAnchorTypes[] = {
    nullptr,
};
static const wl_interface* _CXdgPositionerSetGravityTypes[] = {
    nullptr,
};
static const wl_interface* _CXdgPositionerSetConstraintAdjustmentTypes[] = {
    nullptr,
};
static const wl_interface* _CXdgPositionerSetOffsetTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgPositionerSetParentSizeTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgPositionerSetParentConfigureTypes[] = {
    nullptr,
};

static const wl_message _CXdgPositionerRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "set_size", "ii", _CXdgPositionerSetSizeTypes + 0},
    { "set_anchor_rect", "iiii", _CXdgPositionerSetAnchorRectTypes + 0},
    { "set_anchor", "u", _CXdgPositionerSetAnchorTypes + 0},
    { "set_gravity", "u", _CXdgPositionerSetGravityTypes + 0},
    { "set_constraint_adjustment", "u", _CXdgPositionerSetConstraintAdjustmentTypes + 0},
    { "set_offset", "ii", _CXdgPositionerSetOffsetTypes + 0},
    { "set_reactive", "3", dummyTypes + 0},
    { "set_parent_size", "3ii", _CXdgPositionerSetParentSizeTypes + 0},
    { "set_parent_configure", "3u", _CXdgPositionerSetParentConfigureTypes + 0},
};

const wl_interface xdg_positioner_interface = {
    "xdg_positioner", 6,
    10, _CXdgPositionerRequests,
    0, nullptr,
};

CCXdgPositioner::CCXdgPositioner(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCXdgPositionerVTable, this);
}

CCXdgPositioner::~CCXdgPositioner() {
    if (!destroyed)
        sendDestroy();
}

static void _CXdgSurfaceConfigure(void* data, void* resource, uint32_t serial) {
    const auto PO = (CCXdgSurface*)data;
    if (PO && PO->requests.configure)
        PO->requests.configure(PO, serial);
}

static const void* _CCXdgSurfaceVTable[] = {
    (void*)_CXdgSurfaceConfigure,
};

void CCXdgSurface::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

wl_proxy* CCXdgSurface::sendGetToplevel() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, &xdg_toplevel_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

wl_proxy* CCXdgSurface::sendGetPopup(CCXdgSurface* parent, CCXdgPositioner* positioner) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, &xdg_popup_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, parent ? parent->pResource : nullptr, positioner ? positioner->pResource : nullptr);

    return proxy;
}

void CCXdgSurface::sendSetWindowGeometry(int32_t x, int32_t y, int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y, width, height);
    proxy;
}

void CCXdgSurface::sendAckConfigure(uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, serial);
    proxy;
}
static const wl_interface* _CXdgSurfaceGetToplevelTypes[] = {
    &xdg_toplevel_interface,
};
static const wl_interface* _CXdgSurfaceGetPopupTypes[] = {
    &xdg_popup_interface,
    &xdg_surface_interface,
    &xdg_positioner_interface,
};
static const wl_interface* _CXdgSurfaceSetWindowGeometryTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgSurfaceAckConfigureTypes[] = {
    nullptr,
};
static const wl_interface* _CXdgSurfaceConfigureTypes[] = {
    nullptr,
};

static const wl_message _CXdgSurfaceRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "get_toplevel", "n", _CXdgSurfaceGetToplevelTypes + 0},
    { "get_popup", "n?oo", _CXdgSurfaceGetPopupTypes + 0},
    { "set_window_geometry", "iiii", _CXdgSurfaceSetWindowGeometryTypes + 0},
    { "ack_configure", "u", _CXdgSurfaceAckConfigureTypes + 0},
};

static const wl_message _CXdgSurfaceEvents[] = {
    { "configure", "u", _CXdgSurfaceConfigureTypes + 0},
};

const wl_interface xdg_surface_interface = {
    "xdg_surface", 6,
    5, _CXdgSurfaceRequests,
    1, _CXdgSurfaceEvents,
};

CCXdgSurface::CCXdgSurface(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCXdgSurfaceVTable, this);
}

CCXdgSurface::~CCXdgSurface() {
    if (!destroyed)
        sendDestroy();
}

void CCXdgSurface::setConfigure(F<void(CCXdgSurface*, uint32_t)> handler) {
    requests.configure = handler;
}

static void _CXdgToplevelConfigure(void* data, void* resource, int32_t width, int32_t height, wl_array* states) {
    const auto PO = (CCXdgToplevel*)data;
    if (PO && PO->requests.configure)
        PO->requests.configure(PO, width, height, states);
}

static void _CXdgToplevelClose(void* data, void* resource) {
    const auto PO = (CCXdgToplevel*)data;
    if (PO && PO->requests.close)
        PO->requests.close(PO);
}

static void _CXdgToplevelConfigureBounds(void* data, void* resource, int32_t width, int32_t height) {
    const auto PO = (CCXdgToplevel*)data;
    if (PO && PO->requests.configureBounds)
        PO->requests.configureBounds(PO, width, height);
}

static void _CXdgToplevelWmCapabilities(void* data, void* resource, wl_array* capabilities) {
    const auto PO = (CCXdgToplevel*)data;
    if (PO && PO->requests.wmCapabilities)
        PO->requests.wmCapabilities(PO, capabilities);
}

static const void* _CCXdgToplevelVTable[] = {
    (void*)_CXdgToplevelConfigure,
    (void*)_CXdgToplevelClose,
    (void*)_CXdgToplevelConfigureBounds,
    (void*)_CXdgToplevelWmCapabilities,
};

void CCXdgToplevel::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCXdgToplevel::sendSetParent(CCXdgToplevel* parent) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, parent ? parent->pResource : nullptr);
    proxy;
}

void CCXdgToplevel::sendSetTitle(const char* title) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, title);
    proxy;
}

void CCXdgToplevel::sendSetAppId(const char* app_id) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, app_id);
    proxy;
}

void CCXdgToplevel::sendShowWindowMenu(wl_proxy* seat, uint32_t serial, int32_t x, int32_t y) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, seat, serial, x, y);
    proxy;
}

void CCXdgToplevel::sendMove(wl_proxy* seat, uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 5, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, seat, serial);
    proxy;
}

void CCXdgToplevel::sendResize(wl_proxy* seat, uint32_t serial, xdgToplevelResizeEdge edges) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 6, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, seat, serial, edges);
    proxy;
}

void CCXdgToplevel::sendSetMaxSize(int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 7, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, width, height);
    proxy;
}

void CCXdgToplevel::sendSetMinSize(int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 8, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, width, height);
    proxy;
}

void CCXdgToplevel::sendSetMaximized() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 9, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCXdgToplevel::sendUnsetMaximized() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 10, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCXdgToplevel::sendSetFullscreen(wl_proxy* output) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 11, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, output);
    proxy;
}

void CCXdgToplevel::sendUnsetFullscreen() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 12, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCXdgToplevel::sendSetMinimized() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 13, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}
static const wl_interface* _CXdgToplevelSetParentTypes[] = {
    &xdg_toplevel_interface,
};
static const wl_interface* _CXdgToplevelSetTitleTypes[] = {
    nullptr,
};
static const wl_interface* _CXdgToplevelSetAppIdTypes[] = {
    nullptr,
};
static const wl_interface* _CXdgToplevelShowWindowMenuTypes[] = {
    &wl_seat_interface,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgToplevelMoveTypes[] = {
    &wl_seat_interface,
    nullptr,
};
static const wl_interface* _CXdgToplevelResizeTypes[] = {
    &wl_seat_interface,
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgToplevelSetMaxSizeTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgToplevelSetMinSizeTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgToplevelSetFullscreenTypes[] = {
    &wl_output_interface,
};
static const wl_interface* _CXdgToplevelConfigureTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgToplevelConfigureBoundsTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgToplevelWmCapabilitiesTypes[] = {
    nullptr,
};

static const wl_message _CXdgToplevelRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "set_parent", "?o", _CXdgToplevelSetParentTypes + 0},
    { "set_title", "s", _CXdgToplevelSetTitleTypes + 0},
    { "set_app_id", "s", _CXdgToplevelSetAppIdTypes + 0},
    { "show_window_menu", "ouii", _CXdgToplevelShowWindowMenuTypes + 0},
    { "move", "ou", _CXdgToplevelMoveTypes + 0},
    { "resize", "ouu", _CXdgToplevelResizeTypes + 0},
    { "set_max_size", "ii", _CXdgToplevelSetMaxSizeTypes + 0},
    { "set_min_size", "ii", _CXdgToplevelSetMinSizeTypes + 0},
    { "set_maximized", "", dummyTypes + 0},
    { "unset_maximized", "", dummyTypes + 0},
    { "set_fullscreen", "?o", _CXdgToplevelSetFullscreenTypes + 0},
    { "unset_fullscreen", "", dummyTypes + 0},
    { "set_minimized", "", dummyTypes + 0},
};

static const wl_message _CXdgToplevelEvents[] = {
    { "configure", "iia", _CXdgToplevelConfigureTypes + 0},
    { "close", "", dummyTypes + 0},
    { "configure_bounds", "4ii", _CXdgToplevelConfigureBoundsTypes + 0},
    { "wm_capabilities", "5a", _CXdgToplevelWmCapabilitiesTypes + 0},
};

const wl_interface xdg_toplevel_interface = {
    "xdg_toplevel", 6,
    14, _CXdgToplevelRequests,
    4, _CXdgToplevelEvents,
};

CCXdgToplevel::CCXdgToplevel(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCXdgToplevelVTable, this);
}

CCXdgToplevel::~CCXdgToplevel() {
    if (!destroyed)
        sendDestroy();
}

void CCXdgToplevel::setConfigure(F<void(CCXdgToplevel*, int32_t, int32_t, wl_array*)> handler) {
    requests.configure = handler;
}

void CCXdgToplevel::setClose(F<void(CCXdgToplevel*)> handler) {
    requests.close = handler;
}

void CCXdgToplevel::setConfigureBounds(F<void(CCXdgToplevel*, int32_t, int32_t)> handler) {
    requests.configureBounds = handler;
}

void CCXdgToplevel::setWmCapabilities(F<void(CCXdgToplevel*, wl_array*)> handler) {
    requests.wmCapabilities = handler;
}

static void _CXdgPopupConfigure(void* data, void* resource, int32_t x, int32_t y, int32_t width, int32_t height) {
    const auto PO = (CCXdgPopup*)data;
    if (PO && PO->requests.configure)
        PO->requests.configure(PO, x, y, width, height);
}

static void _CXdgPopupPopupDone(void* data, void* resource) {
    const auto PO = (CCXdgPopup*)data;
    if (PO && PO->requests.popupDone)
        PO->requests.popupDone(PO);
}

static void _CXdgPopupRepositioned(void* data, void* resource, uint32_t token) {
    const auto PO = (CCXdgPopup*)data;
    if (PO && PO->requests.repositioned)
        PO->requests.repositioned(PO, token);
}

static const void* _CCXdgPopupVTable[] = {
    (void*)_CXdgPopupConfigure,
    (void*)_CXdgPopupPopupDone,
    (void*)_CXdgPopupRepositioned,
};

void CCXdgPopup::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCXdgPopup::sendGrab(wl_proxy* seat, uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, seat, serial);
    proxy;
}

void CCXdgPopup::sendReposition(CCXdgPositioner* positioner, uint32_t token) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, positioner ? positioner->pResource : nullptr, token);
    proxy;
}
static const wl_interface* _CXdgPopupGrabTypes[] = {
    &wl_seat_interface,
    nullptr,
};
static const wl_interface* _CXdgPopupRepositionTypes[] = {
    &xdg_positioner_interface,
    nullptr,
};
static const wl_interface* _CXdgPopupConfigureTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CXdgPopupRepositionedTypes[] = {
    nullptr,
};

static const wl_message _CXdgPopupRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "grab", "ou", _CXdgPopupGrabTypes + 0},
    { "reposition", "3ou", _CXdgPopupRepositionTypes + 0},
};

static const wl_message _CXdgPopupEvents[] = {
    { "configure", "iiii", _CXdgPopupConfigureTypes + 0},
    { "popup_done", "", dummyTypes + 0},
    { "repositioned", "3u", _CXdgPopupRepositionedTypes + 0},
};

const wl_interface xdg_popup_interface = {
    "xdg_popup", 6,
    3, _CXdgPopupRequests,
    3, _CXdgPopupEvents,
};

CCXdgPopup::CCXdgPopup(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCXdgPopupVTable, this);
}

CCXdgPopup::~CCXdgPopup() {
    if (!destroyed)
        sendDestroy();
}

void CCXdgPopup::setConfigure(F<void(CCXdgPopup*, int32_t, int32_t, int32_t, int32_t)> handler) {
    requests.configure = handler;
}

void CCXdgPopup::setPopupDone(F<void(CCXdgPopup*)> handler) {
    requests.popupDone = handler;
}

void CCXdgPopup::setRepositioned(F<void(CCXdgPopup*, uint32_t)> handler) {
    requests.repositioned = handler;
}

#undef F
