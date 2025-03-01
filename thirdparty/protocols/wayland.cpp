// Generated with hyprwayland-scanner 0.4.4. Made with vaxry's keyboard and ❤️.
// wayland

/*
 This protocol's authors' copyright notice is:


    Copyright © 2008-2011 Kristian Høgsberg
    Copyright © 2010-2011 Intel Corporation
    Copyright © 2012-2013 Collabora, Ltd.

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation files
    (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice (including the
    next paragraph) shall be included in all copies or substantial
    portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
    BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
    ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
  
*/

#define private public
#define HYPRWAYLAND_SCANNER_NO_INTERFACES
#include "wayland.hpp"
#undef private
#define F std::function

static const wl_interface* dummyTypes[] = { nullptr };

// Reference all other interfaces.
// The reason why this is in snake is to
// be able to cooperate with existing
// wayland_scanner interfaces (they are interop)
extern const wl_interface wl_display_interface;
extern const wl_interface wl_registry_interface;
extern const wl_interface wl_callback_interface;
extern const wl_interface wl_compositor_interface;
extern const wl_interface wl_shm_pool_interface;
extern const wl_interface wl_shm_interface;
extern const wl_interface wl_buffer_interface;
extern const wl_interface wl_data_offer_interface;
extern const wl_interface wl_data_source_interface;
extern const wl_interface wl_data_device_interface;
extern const wl_interface wl_data_device_manager_interface;
extern const wl_interface wl_shell_interface;
extern const wl_interface wl_shell_surface_interface;
extern const wl_interface wl_surface_interface;
extern const wl_interface wl_seat_interface;
extern const wl_interface wl_pointer_interface;
extern const wl_interface wl_keyboard_interface;
extern const wl_interface wl_touch_interface;
extern const wl_interface wl_output_interface;
extern const wl_interface wl_region_interface;
extern const wl_interface wl_subcompositor_interface;
extern const wl_interface wl_subsurface_interface;

static void _CWlDisplayError(void* data, void* resource, wl_proxy* object_id, uint32_t code, const char* message) {
    const auto PO = (CCWlDisplay*)data;
    if (PO && PO->requests.error)
        PO->requests.error(PO, object_id, code, message);
}

static void _CWlDisplayDeleteId(void* data, void* resource, uint32_t id) {
    const auto PO = (CCWlDisplay*)data;
    if (PO && PO->requests.deleteId)
        PO->requests.deleteId(PO, id);
}

static const void* _CCWlDisplayVTable[] = {
    (void*)_CWlDisplayError,
    (void*)_CWlDisplayDeleteId,
};

wl_proxy* CCWlDisplay::sendSync() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &wl_callback_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

wl_proxy* CCWlDisplay::sendGetRegistry() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, &wl_registry_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}
static const wl_interface* _CWlDisplaySyncTypes[] = {
    &wl_callback_interface,
};
static const wl_interface* _CWlDisplayGetRegistryTypes[] = {
    &wl_registry_interface,
};
static const wl_interface* _CWlDisplayErrorTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlDisplayDeleteIdTypes[] = {
    nullptr,
};

static const wl_message _CWlDisplayRequests[] = {
    { "sync", "n", _CWlDisplaySyncTypes + 0},
    { "get_registry", "n", _CWlDisplayGetRegistryTypes + 0},
};

static const wl_message _CWlDisplayEvents[] = {
    { "error", "ous", _CWlDisplayErrorTypes + 0},
    { "delete_id", "u", _CWlDisplayDeleteIdTypes + 0},
};

const wl_interface wl_display_interface = {
    "wl_display", 1,
    2, _CWlDisplayRequests,
    2, _CWlDisplayEvents,
};

CCWlDisplay::CCWlDisplay(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlDisplayVTable, this);
}

CCWlDisplay::~CCWlDisplay() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

void CCWlDisplay::setError(F<void(CCWlDisplay*, wl_proxy*, uint32_t, const char*)> handler) {
    requests.error = handler;
}

void CCWlDisplay::setDeleteId(F<void(CCWlDisplay*, uint32_t)> handler) {
    requests.deleteId = handler;
}

static void _CWlRegistryGlobal(void* data, void* resource, uint32_t name, const char* interface, uint32_t version) {
    const auto PO = (CCWlRegistry*)data;
    if (PO && PO->requests.global)
        PO->requests.global(PO, name, interface, version);
}

static void _CWlRegistryGlobalRemove(void* data, void* resource, uint32_t name) {
    const auto PO = (CCWlRegistry*)data;
    if (PO && PO->requests.globalRemove)
        PO->requests.globalRemove(PO, name);
}

static const void* _CCWlRegistryVTable[] = {
    (void*)_CWlRegistryGlobal,
    (void*)_CWlRegistryGlobalRemove,
};

void CCWlRegistry::sendBind(uint32_t name) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, name, nullptr);
    proxy;
}
static const wl_interface* _CWlRegistryBindTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlRegistryGlobalTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlRegistryGlobalRemoveTypes[] = {
    nullptr,
};

static const wl_message _CWlRegistryRequests[] = {
    { "bind", "usun", _CWlRegistryBindTypes + 0},
};

static const wl_message _CWlRegistryEvents[] = {
    { "global", "usu", _CWlRegistryGlobalTypes + 0},
    { "global_remove", "u", _CWlRegistryGlobalRemoveTypes + 0},
};

const wl_interface wl_registry_interface = {
    "wl_registry", 1,
    1, _CWlRegistryRequests,
    2, _CWlRegistryEvents,
};

CCWlRegistry::CCWlRegistry(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlRegistryVTable, this);
}

CCWlRegistry::~CCWlRegistry() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

void CCWlRegistry::setGlobal(F<void(CCWlRegistry*, uint32_t, const char*, uint32_t)> handler) {
    requests.global = handler;
}

void CCWlRegistry::setGlobalRemove(F<void(CCWlRegistry*, uint32_t)> handler) {
    requests.globalRemove = handler;
}

static void _CWlCallbackDone(void* data, void* resource, uint32_t callback_data) {
    const auto PO = (CCWlCallback*)data;
    if (PO && PO->requests.done)
        PO->requests.done(PO, callback_data);
}

static const void* _CCWlCallbackVTable[] = {
    (void*)_CWlCallbackDone,
};
static const wl_interface* _CWlCallbackDoneTypes[] = {
    nullptr,
};

static const wl_message _CWlCallbackEvents[] = {
    { "done", "u", _CWlCallbackDoneTypes + 0},
};

const wl_interface wl_callback_interface = {
    "wl_callback", 1,
    0, nullptr,
    1, _CWlCallbackEvents,
};

CCWlCallback::CCWlCallback(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlCallbackVTable, this);
}

CCWlCallback::~CCWlCallback() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

void CCWlCallback::setDone(F<void(CCWlCallback*, uint32_t)> handler) {
    requests.done = handler;
}

static const void* _CCWlCompositorVTable[] = {
};

wl_proxy* CCWlCompositor::sendCreateSurface() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &wl_surface_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

wl_proxy* CCWlCompositor::sendCreateRegion() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, &wl_region_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}
static const wl_interface* _CWlCompositorCreateSurfaceTypes[] = {
    &wl_surface_interface,
};
static const wl_interface* _CWlCompositorCreateRegionTypes[] = {
    &wl_region_interface,
};

static const wl_message _CWlCompositorRequests[] = {
    { "create_surface", "n", _CWlCompositorCreateSurfaceTypes + 0},
    { "create_region", "n", _CWlCompositorCreateRegionTypes + 0},
};

const wl_interface wl_compositor_interface = {
    "wl_compositor", 6,
    2, _CWlCompositorRequests,
    0, nullptr,
};

CCWlCompositor::CCWlCompositor(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlCompositorVTable, this);
}

CCWlCompositor::~CCWlCompositor() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

static const void* _CCWlShmPoolVTable[] = {
};

wl_proxy* CCWlShmPool::sendCreateBuffer(int32_t offset, int32_t width, int32_t height, int32_t stride, uint32_t format) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &wl_buffer_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, offset, width, height, stride, format);

    return proxy;
}

void CCWlShmPool::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCWlShmPool::sendResize(int32_t size) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, size);
    proxy;
}
static const wl_interface* _CWlShmPoolCreateBufferTypes[] = {
    &wl_buffer_interface,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlShmPoolResizeTypes[] = {
    nullptr,
};

static const wl_message _CWlShmPoolRequests[] = {
    { "create_buffer", "niiiiu", _CWlShmPoolCreateBufferTypes + 0},
    { "destroy", "", dummyTypes + 0},
    { "resize", "i", _CWlShmPoolResizeTypes + 0},
};

const wl_interface wl_shm_pool_interface = {
    "wl_shm_pool", 2,
    3, _CWlShmPoolRequests,
    0, nullptr,
};

CCWlShmPool::CCWlShmPool(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlShmPoolVTable, this);
}

CCWlShmPool::~CCWlShmPool() {
    if (!destroyed)
        sendDestroy();
}

static void _CWlShmFormat(void* data, void* resource, enum wl_shm_format format) {
    const auto PO = (CCWlShm*)data;
    if (PO && PO->requests.format)
        PO->requests.format(PO, format);
}

static const void* _CCWlShmVTable[] = {
    (void*)_CWlShmFormat,
};

wl_proxy* CCWlShm::sendCreatePool(int32_t fd, int32_t size) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &wl_shm_pool_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, fd, size);

    return proxy;
}

void CCWlShm::sendRelease() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CWlShmCreatePoolTypes[] = {
    &wl_shm_pool_interface,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlShmFormatTypes[] = {
    nullptr,
};

static const wl_message _CWlShmRequests[] = {
    { "create_pool", "nhi", _CWlShmCreatePoolTypes + 0},
    { "release", "2", dummyTypes + 0},
};

static const wl_message _CWlShmEvents[] = {
    { "format", "u", _CWlShmFormatTypes + 0},
};

const wl_interface wl_shm_interface = {
    "wl_shm", 2,
    2, _CWlShmRequests,
    1, _CWlShmEvents,
};

CCWlShm::CCWlShm(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlShmVTable, this);
}

CCWlShm::~CCWlShm() {
    if (!destroyed)
        sendRelease();
}

void CCWlShm::setFormat(F<void(CCWlShm*, enum wl_shm_format)> handler) {
    requests.format = handler;
}

static void _CWlBufferRelease(void* data, void* resource) {
    const auto PO = (CCWlBuffer*)data;
    if (PO && PO->requests.release)
        PO->requests.release(PO);
}

static const void* _CCWlBufferVTable[] = {
    (void*)_CWlBufferRelease,
};

void CCWlBuffer::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

static const wl_message _CWlBufferRequests[] = {
    { "destroy", "", dummyTypes + 0},
};

static const wl_message _CWlBufferEvents[] = {
    { "release", "", dummyTypes + 0},
};

const wl_interface wl_buffer_interface = {
    "wl_buffer", 1,
    1, _CWlBufferRequests,
    1, _CWlBufferEvents,
};

CCWlBuffer::CCWlBuffer(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlBufferVTable, this);
}

CCWlBuffer::~CCWlBuffer() {
    if (!destroyed)
        sendDestroy();
}

void CCWlBuffer::setRelease(F<void(CCWlBuffer*)> handler) {
    requests.release = handler;
}

static void _CWlDataOfferOffer(void* data, void* resource, const char* mime_type) {
    const auto PO = (CCWlDataOffer*)data;
    if (PO && PO->requests.offer)
        PO->requests.offer(PO, mime_type);
}

static void _CWlDataOfferSourceActions(void* data, void* resource, uint32_t source_actions) {
    const auto PO = (CCWlDataOffer*)data;
    if (PO && PO->requests.sourceActions)
        PO->requests.sourceActions(PO, source_actions);
}

static void _CWlDataOfferAction(void* data, void* resource, uint32_t dnd_action) {
    const auto PO = (CCWlDataOffer*)data;
    if (PO && PO->requests.action)
        PO->requests.action(PO, dnd_action);
}

static const void* _CCWlDataOfferVTable[] = {
    (void*)_CWlDataOfferOffer,
    (void*)_CWlDataOfferSourceActions,
    (void*)_CWlDataOfferAction,
};

void CCWlDataOffer::sendAccept(uint32_t serial, const char* mime_type) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, serial, mime_type);
    proxy;
}

void CCWlDataOffer::sendReceive(const char* mime_type, int32_t fd) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, mime_type, fd);
    proxy;
}

void CCWlDataOffer::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCWlDataOffer::sendFinish() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCWlDataOffer::sendSetActions(uint32_t dnd_actions, uint32_t preferred_action) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, dnd_actions, preferred_action);
    proxy;
}
static const wl_interface* _CWlDataOfferAcceptTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlDataOfferReceiveTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlDataOfferSetActionsTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlDataOfferOfferTypes[] = {
    nullptr,
};
static const wl_interface* _CWlDataOfferSourceActionsTypes[] = {
    nullptr,
};
static const wl_interface* _CWlDataOfferActionTypes[] = {
    nullptr,
};

static const wl_message _CWlDataOfferRequests[] = {
    { "accept", "u?s", _CWlDataOfferAcceptTypes + 0},
    { "receive", "sh", _CWlDataOfferReceiveTypes + 0},
    { "destroy", "", dummyTypes + 0},
    { "finish", "3", dummyTypes + 0},
    { "set_actions", "3uu", _CWlDataOfferSetActionsTypes + 0},
};

static const wl_message _CWlDataOfferEvents[] = {
    { "offer", "s", _CWlDataOfferOfferTypes + 0},
    { "source_actions", "3u", _CWlDataOfferSourceActionsTypes + 0},
    { "action", "3u", _CWlDataOfferActionTypes + 0},
};

const wl_interface wl_data_offer_interface = {
    "wl_data_offer", 3,
    5, _CWlDataOfferRequests,
    3, _CWlDataOfferEvents,
};

CCWlDataOffer::CCWlDataOffer(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlDataOfferVTable, this);
}

CCWlDataOffer::~CCWlDataOffer() {
    if (!destroyed)
        sendDestroy();
}

void CCWlDataOffer::setOffer(F<void(CCWlDataOffer*, const char*)> handler) {
    requests.offer = handler;
}

void CCWlDataOffer::setSourceActions(F<void(CCWlDataOffer*, uint32_t)> handler) {
    requests.sourceActions = handler;
}

void CCWlDataOffer::setAction(F<void(CCWlDataOffer*, uint32_t)> handler) {
    requests.action = handler;
}

static void _CWlDataSourceTarget(void* data, void* resource, const char* mime_type) {
    const auto PO = (CCWlDataSource*)data;
    if (PO && PO->requests.target)
        PO->requests.target(PO, mime_type);
}

static void _CWlDataSourceSend(void* data, void* resource, const char* mime_type, int32_t fd) {
    const auto PO = (CCWlDataSource*)data;
    if (PO && PO->requests.send)
        PO->requests.send(PO, mime_type, fd);
}

static void _CWlDataSourceCancelled(void* data, void* resource) {
    const auto PO = (CCWlDataSource*)data;
    if (PO && PO->requests.cancelled)
        PO->requests.cancelled(PO);
}

static void _CWlDataSourceDndDropPerformed(void* data, void* resource) {
    const auto PO = (CCWlDataSource*)data;
    if (PO && PO->requests.dndDropPerformed)
        PO->requests.dndDropPerformed(PO);
}

static void _CWlDataSourceDndFinished(void* data, void* resource) {
    const auto PO = (CCWlDataSource*)data;
    if (PO && PO->requests.dndFinished)
        PO->requests.dndFinished(PO);
}

static void _CWlDataSourceAction(void* data, void* resource, uint32_t dnd_action) {
    const auto PO = (CCWlDataSource*)data;
    if (PO && PO->requests.action)
        PO->requests.action(PO, dnd_action);
}

static const void* _CCWlDataSourceVTable[] = {
    (void*)_CWlDataSourceTarget,
    (void*)_CWlDataSourceSend,
    (void*)_CWlDataSourceCancelled,
    (void*)_CWlDataSourceDndDropPerformed,
    (void*)_CWlDataSourceDndFinished,
    (void*)_CWlDataSourceAction,
};

void CCWlDataSource::sendOffer(const char* mime_type) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, mime_type);
    proxy;
}

void CCWlDataSource::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCWlDataSource::sendSetActions(uint32_t dnd_actions) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, dnd_actions);
    proxy;
}
static const wl_interface* _CWlDataSourceOfferTypes[] = {
    nullptr,
};
static const wl_interface* _CWlDataSourceSetActionsTypes[] = {
    nullptr,
};
static const wl_interface* _CWlDataSourceTargetTypes[] = {
    nullptr,
};
static const wl_interface* _CWlDataSourceSendTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlDataSourceActionTypes[] = {
    nullptr,
};

static const wl_message _CWlDataSourceRequests[] = {
    { "offer", "s", _CWlDataSourceOfferTypes + 0},
    { "destroy", "", dummyTypes + 0},
    { "set_actions", "3u", _CWlDataSourceSetActionsTypes + 0},
};

static const wl_message _CWlDataSourceEvents[] = {
    { "target", "?s", _CWlDataSourceTargetTypes + 0},
    { "send", "sh", _CWlDataSourceSendTypes + 0},
    { "cancelled", "", dummyTypes + 0},
    { "dnd_drop_performed", "3", dummyTypes + 0},
    { "dnd_finished", "3", dummyTypes + 0},
    { "action", "3u", _CWlDataSourceActionTypes + 0},
};

const wl_interface wl_data_source_interface = {
    "wl_data_source", 3,
    3, _CWlDataSourceRequests,
    6, _CWlDataSourceEvents,
};

CCWlDataSource::CCWlDataSource(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlDataSourceVTable, this);
}

CCWlDataSource::~CCWlDataSource() {
    if (!destroyed)
        sendDestroy();
}

void CCWlDataSource::setTarget(F<void(CCWlDataSource*, const char*)> handler) {
    requests.target = handler;
}

void CCWlDataSource::setSend(F<void(CCWlDataSource*, const char*, int32_t)> handler) {
    requests.send = handler;
}

void CCWlDataSource::setCancelled(F<void(CCWlDataSource*)> handler) {
    requests.cancelled = handler;
}

void CCWlDataSource::setDndDropPerformed(F<void(CCWlDataSource*)> handler) {
    requests.dndDropPerformed = handler;
}

void CCWlDataSource::setDndFinished(F<void(CCWlDataSource*)> handler) {
    requests.dndFinished = handler;
}

void CCWlDataSource::setAction(F<void(CCWlDataSource*, uint32_t)> handler) {
    requests.action = handler;
}

static void _CWlDataDeviceDataOffer(void* data, void* resource, wl_proxy* id) {
    const auto PO = (CCWlDataDevice*)data;
    if (PO && PO->requests.dataOffer)
        PO->requests.dataOffer(PO, id);
}

static void _CWlDataDeviceEnter(void* data, void* resource, uint32_t serial, wl_proxy* surface, wl_fixed_t x, wl_fixed_t y, wl_proxy* id) {
    const auto PO = (CCWlDataDevice*)data;
    if (PO && PO->requests.enter)
        PO->requests.enter(PO, serial, surface, x, y, id);
}

static void _CWlDataDeviceLeave(void* data, void* resource) {
    const auto PO = (CCWlDataDevice*)data;
    if (PO && PO->requests.leave)
        PO->requests.leave(PO);
}

static void _CWlDataDeviceMotion(void* data, void* resource, uint32_t time, wl_fixed_t x, wl_fixed_t y) {
    const auto PO = (CCWlDataDevice*)data;
    if (PO && PO->requests.motion)
        PO->requests.motion(PO, time, x, y);
}

static void _CWlDataDeviceDrop(void* data, void* resource) {
    const auto PO = (CCWlDataDevice*)data;
    if (PO && PO->requests.drop)
        PO->requests.drop(PO);
}

static void _CWlDataDeviceSelection(void* data, void* resource, wl_proxy* id) {
    const auto PO = (CCWlDataDevice*)data;
    if (PO && PO->requests.selection)
        PO->requests.selection(PO, id);
}

static const void* _CCWlDataDeviceVTable[] = {
    (void*)_CWlDataDeviceDataOffer,
    (void*)_CWlDataDeviceEnter,
    (void*)_CWlDataDeviceLeave,
    (void*)_CWlDataDeviceMotion,
    (void*)_CWlDataDeviceDrop,
    (void*)_CWlDataDeviceSelection,
};

void CCWlDataDevice::sendStartDrag(CCWlDataSource* source, CCWlSurface* origin, CCWlSurface* icon, uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, source ? source->pResource : nullptr, origin ? origin->pResource : nullptr, icon ? icon->pResource : nullptr, serial);
    proxy;
}

void CCWlDataDevice::sendSetSelection(CCWlDataSource* source, uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, source ? source->pResource : nullptr, serial);
    proxy;
}

void CCWlDataDevice::sendRelease() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CWlDataDeviceStartDragTypes[] = {
    &wl_data_source_interface,
    &wl_surface_interface,
    &wl_surface_interface,
    nullptr,
};
static const wl_interface* _CWlDataDeviceSetSelectionTypes[] = {
    &wl_data_source_interface,
    nullptr,
};
static const wl_interface* _CWlDataDeviceDataOfferTypes[] = {
    &wl_data_offer_interface,
};
static const wl_interface* _CWlDataDeviceEnterTypes[] = {
    nullptr,
    &wl_surface_interface,
    nullptr,
    nullptr,
    &wl_data_offer_interface,
};
static const wl_interface* _CWlDataDeviceMotionTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlDataDeviceSelectionTypes[] = {
    &wl_data_offer_interface,
};

static const wl_message _CWlDataDeviceRequests[] = {
    { "start_drag", "?oo?ou", _CWlDataDeviceStartDragTypes + 0},
    { "set_selection", "?ou", _CWlDataDeviceSetSelectionTypes + 0},
    { "release", "2", dummyTypes + 0},
};

static const wl_message _CWlDataDeviceEvents[] = {
    { "data_offer", "n", _CWlDataDeviceDataOfferTypes + 0},
    { "enter", "uoff?o", _CWlDataDeviceEnterTypes + 0},
    { "leave", "", dummyTypes + 0},
    { "motion", "uff", _CWlDataDeviceMotionTypes + 0},
    { "drop", "", dummyTypes + 0},
    { "selection", "?o", _CWlDataDeviceSelectionTypes + 0},
};

const wl_interface wl_data_device_interface = {
    "wl_data_device", 3,
    3, _CWlDataDeviceRequests,
    6, _CWlDataDeviceEvents,
};

CCWlDataDevice::CCWlDataDevice(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlDataDeviceVTable, this);
}

CCWlDataDevice::~CCWlDataDevice() {
    if (!destroyed)
        sendRelease();
}

void CCWlDataDevice::setDataOffer(F<void(CCWlDataDevice*, wl_proxy*)> handler) {
    requests.dataOffer = handler;
}

void CCWlDataDevice::setEnter(F<void(CCWlDataDevice*, uint32_t, wl_proxy*, wl_fixed_t, wl_fixed_t, wl_proxy*)> handler) {
    requests.enter = handler;
}

void CCWlDataDevice::setLeave(F<void(CCWlDataDevice*)> handler) {
    requests.leave = handler;
}

void CCWlDataDevice::setMotion(F<void(CCWlDataDevice*, uint32_t, wl_fixed_t, wl_fixed_t)> handler) {
    requests.motion = handler;
}

void CCWlDataDevice::setDrop(F<void(CCWlDataDevice*)> handler) {
    requests.drop = handler;
}

void CCWlDataDevice::setSelection(F<void(CCWlDataDevice*, wl_proxy*)> handler) {
    requests.selection = handler;
}

static const void* _CCWlDataDeviceManagerVTable[] = {
};

wl_proxy* CCWlDataDeviceManager::sendCreateDataSource() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &wl_data_source_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

wl_proxy* CCWlDataDeviceManager::sendGetDataDevice(CCWlSeat* seat) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, &wl_data_device_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, seat ? seat->pResource : nullptr);

    return proxy;
}
static const wl_interface* _CWlDataDeviceManagerCreateDataSourceTypes[] = {
    &wl_data_source_interface,
};
static const wl_interface* _CWlDataDeviceManagerGetDataDeviceTypes[] = {
    &wl_data_device_interface,
    &wl_seat_interface,
};

static const wl_message _CWlDataDeviceManagerRequests[] = {
    { "create_data_source", "n", _CWlDataDeviceManagerCreateDataSourceTypes + 0},
    { "get_data_device", "no", _CWlDataDeviceManagerGetDataDeviceTypes + 0},
};

const wl_interface wl_data_device_manager_interface = {
    "wl_data_device_manager", 3,
    2, _CWlDataDeviceManagerRequests,
    0, nullptr,
};

CCWlDataDeviceManager::CCWlDataDeviceManager(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlDataDeviceManagerVTable, this);
}

CCWlDataDeviceManager::~CCWlDataDeviceManager() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

static const void* _CCWlShellVTable[] = {
};

wl_proxy* CCWlShell::sendGetShellSurface(CCWlSurface* surface) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &wl_shell_surface_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, surface ? surface->pResource : nullptr);

    return proxy;
}
static const wl_interface* _CWlShellGetShellSurfaceTypes[] = {
    &wl_shell_surface_interface,
    &wl_surface_interface,
};

static const wl_message _CWlShellRequests[] = {
    { "get_shell_surface", "no", _CWlShellGetShellSurfaceTypes + 0},
};

const wl_interface wl_shell_interface = {
    "wl_shell", 1,
    1, _CWlShellRequests,
    0, nullptr,
};

CCWlShell::CCWlShell(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlShellVTable, this);
}

CCWlShell::~CCWlShell() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

static void _CWlShellSurfacePing(void* data, void* resource, uint32_t serial) {
    const auto PO = (CCWlShellSurface*)data;
    if (PO && PO->requests.ping)
        PO->requests.ping(PO, serial);
}

static void _CWlShellSurfaceConfigure(void* data, void* resource, enum wl_shell_surface_resize edges, int32_t width, int32_t height) {
    const auto PO = (CCWlShellSurface*)data;
    if (PO && PO->requests.configure)
        PO->requests.configure(PO, edges, width, height);
}

static void _CWlShellSurfacePopupDone(void* data, void* resource) {
    const auto PO = (CCWlShellSurface*)data;
    if (PO && PO->requests.popupDone)
        PO->requests.popupDone(PO);
}

static const void* _CCWlShellSurfaceVTable[] = {
    (void*)_CWlShellSurfacePing,
    (void*)_CWlShellSurfaceConfigure,
    (void*)_CWlShellSurfacePopupDone,
};

void CCWlShellSurface::sendPong(uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, serial);
    proxy;
}

void CCWlShellSurface::sendMove(CCWlSeat* seat, uint32_t serial) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, seat ? seat->pResource : nullptr, serial);
    proxy;
}

void CCWlShellSurface::sendResize(CCWlSeat* seat, uint32_t serial, enum wl_shell_surface_resize edges) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, seat ? seat->pResource : nullptr, serial, edges);
    proxy;
}

void CCWlShellSurface::sendSetToplevel() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCWlShellSurface::sendSetTransient(CCWlSurface* parent, int32_t x, int32_t y, enum wl_shell_surface_transient flags) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, parent ? parent->pResource : nullptr, x, y, flags);
    proxy;
}

void CCWlShellSurface::sendSetFullscreen(enum wl_shell_surface_fullscreen_method method, uint32_t framerate, CCWlOutput* output) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 5, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, method, framerate, output ? output->pResource : nullptr);
    proxy;
}

void CCWlShellSurface::sendSetPopup(CCWlSeat* seat, uint32_t serial, CCWlSurface* parent, int32_t x, int32_t y, enum wl_shell_surface_transient flags) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 6, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, seat ? seat->pResource : nullptr, serial, parent ? parent->pResource : nullptr, x, y, flags);
    proxy;
}

void CCWlShellSurface::sendSetMaximized(CCWlOutput* output) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 7, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, output ? output->pResource : nullptr);
    proxy;
}

void CCWlShellSurface::sendSetTitle(const char* title) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 8, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, title);
    proxy;
}

void CCWlShellSurface::sendSetClass(const char* class_) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 9, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, class_);
    proxy;
}
static const wl_interface* _CWlShellSurfacePongTypes[] = {
    nullptr,
};
static const wl_interface* _CWlShellSurfaceMoveTypes[] = {
    &wl_seat_interface,
    nullptr,
};
static const wl_interface* _CWlShellSurfaceResizeTypes[] = {
    &wl_seat_interface,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlShellSurfaceSetTransientTypes[] = {
    &wl_surface_interface,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlShellSurfaceSetFullscreenTypes[] = {
    nullptr,
    nullptr,
    &wl_output_interface,
};
static const wl_interface* _CWlShellSurfaceSetPopupTypes[] = {
    &wl_seat_interface,
    nullptr,
    &wl_surface_interface,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlShellSurfaceSetMaximizedTypes[] = {
    &wl_output_interface,
};
static const wl_interface* _CWlShellSurfaceSetTitleTypes[] = {
    nullptr,
};
static const wl_interface* _CWlShellSurfaceSetClassTypes[] = {
    nullptr,
};
static const wl_interface* _CWlShellSurfacePingTypes[] = {
    nullptr,
};
static const wl_interface* _CWlShellSurfaceConfigureTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};

static const wl_message _CWlShellSurfaceRequests[] = {
    { "pong", "u", _CWlShellSurfacePongTypes + 0},
    { "move", "ou", _CWlShellSurfaceMoveTypes + 0},
    { "resize", "ouu", _CWlShellSurfaceResizeTypes + 0},
    { "set_toplevel", "", dummyTypes + 0},
    { "set_transient", "oiiu", _CWlShellSurfaceSetTransientTypes + 0},
    { "set_fullscreen", "uu?o", _CWlShellSurfaceSetFullscreenTypes + 0},
    { "set_popup", "ouoiiu", _CWlShellSurfaceSetPopupTypes + 0},
    { "set_maximized", "?o", _CWlShellSurfaceSetMaximizedTypes + 0},
    { "set_title", "s", _CWlShellSurfaceSetTitleTypes + 0},
    { "set_class", "s", _CWlShellSurfaceSetClassTypes + 0},
};

static const wl_message _CWlShellSurfaceEvents[] = {
    { "ping", "u", _CWlShellSurfacePingTypes + 0},
    { "configure", "uii", _CWlShellSurfaceConfigureTypes + 0},
    { "popup_done", "", dummyTypes + 0},
};

const wl_interface wl_shell_surface_interface = {
    "wl_shell_surface", 1,
    10, _CWlShellSurfaceRequests,
    3, _CWlShellSurfaceEvents,
};

CCWlShellSurface::CCWlShellSurface(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlShellSurfaceVTable, this);
}

CCWlShellSurface::~CCWlShellSurface() {
    if (!destroyed)
        wl_proxy_destroy(pResource);
}

void CCWlShellSurface::setPing(F<void(CCWlShellSurface*, uint32_t)> handler) {
    requests.ping = handler;
}

void CCWlShellSurface::setConfigure(F<void(CCWlShellSurface*, enum wl_shell_surface_resize, int32_t, int32_t)> handler) {
    requests.configure = handler;
}

void CCWlShellSurface::setPopupDone(F<void(CCWlShellSurface*)> handler) {
    requests.popupDone = handler;
}

static void _CWlSurfaceEnter(void* data, void* resource, wl_proxy* output) {
    const auto PO = (CCWlSurface*)data;
    if (PO && PO->requests.enter)
        PO->requests.enter(PO, output);
}

static void _CWlSurfaceLeave(void* data, void* resource, wl_proxy* output) {
    const auto PO = (CCWlSurface*)data;
    if (PO && PO->requests.leave)
        PO->requests.leave(PO, output);
}

static void _CWlSurfacePreferredBufferScale(void* data, void* resource, int32_t factor) {
    const auto PO = (CCWlSurface*)data;
    if (PO && PO->requests.preferredBufferScale)
        PO->requests.preferredBufferScale(PO, factor);
}

static void _CWlSurfacePreferredBufferTransform(void* data, void* resource, uint32_t transform) {
    const auto PO = (CCWlSurface*)data;
    if (PO && PO->requests.preferredBufferTransform)
        PO->requests.preferredBufferTransform(PO, transform);
}

static const void* _CCWlSurfaceVTable[] = {
    (void*)_CWlSurfaceEnter,
    (void*)_CWlSurfaceLeave,
    (void*)_CWlSurfacePreferredBufferScale,
    (void*)_CWlSurfacePreferredBufferTransform,
};

void CCWlSurface::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCWlSurface::sendAttach(CCWlBuffer* buffer, int32_t x, int32_t y) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, buffer ? buffer->pResource : nullptr, x, y);
    proxy;
}

void CCWlSurface::sendDamage(int32_t x, int32_t y, int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y, width, height);
    proxy;
}

wl_proxy* CCWlSurface::sendFrame() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, &wl_callback_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

void CCWlSurface::sendSetOpaqueRegion(CCWlRegion* region) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, region ? region->pResource : nullptr);
    proxy;
}

void CCWlSurface::sendSetInputRegion(CCWlRegion* region) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 5, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, region ? region->pResource : nullptr);
    proxy;
}

void CCWlSurface::sendCommit() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 6, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCWlSurface::sendSetBufferTransform(int32_t transform) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 7, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, transform);
    proxy;
}

void CCWlSurface::sendSetBufferScale(int32_t scale) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 8, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, scale);
    proxy;
}

void CCWlSurface::sendDamageBuffer(int32_t x, int32_t y, int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 9, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y, width, height);
    proxy;
}

void CCWlSurface::sendOffset(int32_t x, int32_t y) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 10, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y);
    proxy;
}
static const wl_interface* _CWlSurfaceAttachTypes[] = {
    &wl_buffer_interface,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlSurfaceDamageTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlSurfaceFrameTypes[] = {
    &wl_callback_interface,
};
static const wl_interface* _CWlSurfaceSetOpaqueRegionTypes[] = {
    &wl_region_interface,
};
static const wl_interface* _CWlSurfaceSetInputRegionTypes[] = {
    &wl_region_interface,
};
static const wl_interface* _CWlSurfaceSetBufferTransformTypes[] = {
    nullptr,
};
static const wl_interface* _CWlSurfaceSetBufferScaleTypes[] = {
    nullptr,
};
static const wl_interface* _CWlSurfaceDamageBufferTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlSurfaceOffsetTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlSurfaceEnterTypes[] = {
    &wl_output_interface,
};
static const wl_interface* _CWlSurfaceLeaveTypes[] = {
    &wl_output_interface,
};
static const wl_interface* _CWlSurfacePreferredBufferScaleTypes[] = {
    nullptr,
};
static const wl_interface* _CWlSurfacePreferredBufferTransformTypes[] = {
    nullptr,
};

static const wl_message _CWlSurfaceRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "attach", "?oii", _CWlSurfaceAttachTypes + 0},
    { "damage", "iiii", _CWlSurfaceDamageTypes + 0},
    { "frame", "n", _CWlSurfaceFrameTypes + 0},
    { "set_opaque_region", "?o", _CWlSurfaceSetOpaqueRegionTypes + 0},
    { "set_input_region", "?o", _CWlSurfaceSetInputRegionTypes + 0},
    { "commit", "", dummyTypes + 0},
    { "set_buffer_transform", "2i", _CWlSurfaceSetBufferTransformTypes + 0},
    { "set_buffer_scale", "3i", _CWlSurfaceSetBufferScaleTypes + 0},
    { "damage_buffer", "4iiii", _CWlSurfaceDamageBufferTypes + 0},
    { "offset", "5ii", _CWlSurfaceOffsetTypes + 0},
};

static const wl_message _CWlSurfaceEvents[] = {
    { "enter", "o", _CWlSurfaceEnterTypes + 0},
    { "leave", "o", _CWlSurfaceLeaveTypes + 0},
    { "preferred_buffer_scale", "6i", _CWlSurfacePreferredBufferScaleTypes + 0},
    { "preferred_buffer_transform", "6u", _CWlSurfacePreferredBufferTransformTypes + 0},
};

const wl_interface wl_surface_interface = {
    "wl_surface", 6,
    11, _CWlSurfaceRequests,
    4, _CWlSurfaceEvents,
};

CCWlSurface::CCWlSurface(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlSurfaceVTable, this);
}

CCWlSurface::~CCWlSurface() {
    if (!destroyed)
        sendDestroy();
}

void CCWlSurface::setEnter(F<void(CCWlSurface*, wl_proxy*)> handler) {
    requests.enter = handler;
}

void CCWlSurface::setLeave(F<void(CCWlSurface*, wl_proxy*)> handler) {
    requests.leave = handler;
}

void CCWlSurface::setPreferredBufferScale(F<void(CCWlSurface*, int32_t)> handler) {
    requests.preferredBufferScale = handler;
}

void CCWlSurface::setPreferredBufferTransform(F<void(CCWlSurface*, uint32_t)> handler) {
    requests.preferredBufferTransform = handler;
}

static void _CWlSeatCapabilities(void* data, void* resource, enum wl_seat_capability capabilities) {
    const auto PO = (CCWlSeat*)data;
    if (PO && PO->requests.capabilities)
        PO->requests.capabilities(PO, capabilities);
}

static void _CWlSeatName(void* data, void* resource, const char* name) {
    const auto PO = (CCWlSeat*)data;
    if (PO && PO->requests.name)
        PO->requests.name(PO, name);
}

static const void* _CCWlSeatVTable[] = {
    (void*)_CWlSeatCapabilities,
    (void*)_CWlSeatName,
};

wl_proxy* CCWlSeat::sendGetPointer() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, &wl_pointer_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

wl_proxy* CCWlSeat::sendGetKeyboard() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, &wl_keyboard_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

wl_proxy* CCWlSeat::sendGetTouch() {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, &wl_touch_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr);

    return proxy;
}

void CCWlSeat::sendRelease() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CWlSeatGetPointerTypes[] = {
    &wl_pointer_interface,
};
static const wl_interface* _CWlSeatGetKeyboardTypes[] = {
    &wl_keyboard_interface,
};
static const wl_interface* _CWlSeatGetTouchTypes[] = {
    &wl_touch_interface,
};
static const wl_interface* _CWlSeatCapabilitiesTypes[] = {
    nullptr,
};
static const wl_interface* _CWlSeatNameTypes[] = {
    nullptr,
};

static const wl_message _CWlSeatRequests[] = {
    { "get_pointer", "n", _CWlSeatGetPointerTypes + 0},
    { "get_keyboard", "n", _CWlSeatGetKeyboardTypes + 0},
    { "get_touch", "n", _CWlSeatGetTouchTypes + 0},
    { "release", "5", dummyTypes + 0},
};

static const wl_message _CWlSeatEvents[] = {
    { "capabilities", "u", _CWlSeatCapabilitiesTypes + 0},
    { "name", "2s", _CWlSeatNameTypes + 0},
};

const wl_interface wl_seat_interface = {
    "wl_seat", 9,
    4, _CWlSeatRequests,
    2, _CWlSeatEvents,
};

CCWlSeat::CCWlSeat(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlSeatVTable, this);
}

CCWlSeat::~CCWlSeat() {
    if (!destroyed)
        sendRelease();
}

void CCWlSeat::setCapabilities(F<void(CCWlSeat*, enum wl_seat_capability)> handler) {
    requests.capabilities = handler;
}

void CCWlSeat::setName(F<void(CCWlSeat*, const char*)> handler) {
    requests.name = handler;
}

static void _CWlPointerEnter(void* data, void* resource, uint32_t serial, wl_proxy* surface, wl_fixed_t surface_x, wl_fixed_t surface_y) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.enter)
        PO->requests.enter(PO, serial, surface, surface_x, surface_y);
}

static void _CWlPointerLeave(void* data, void* resource, uint32_t serial, wl_proxy* surface) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.leave)
        PO->requests.leave(PO, serial, surface);
}

static void _CWlPointerMotion(void* data, void* resource, uint32_t time, wl_fixed_t surface_x, wl_fixed_t surface_y) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.motion)
        PO->requests.motion(PO, time, surface_x, surface_y);
}

static void _CWlPointerButton(void* data, void* resource, uint32_t serial, uint32_t time, uint32_t button, enum wl_pointer_button_state state) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.button)
        PO->requests.button(PO, serial, time, button, state);
}

static void _CWlPointerAxis(void* data, void* resource, uint32_t time, enum wl_pointer_axis axis, wl_fixed_t value) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.axis)
        PO->requests.axis(PO, time, axis, value);
}

static void _CWlPointerFrame(void* data, void* resource) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.frame)
        PO->requests.frame(PO);
}

static void _CWlPointerAxisSource(void* data, void* resource, enum wl_pointer_axis_source axis_source) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.axisSource)
        PO->requests.axisSource(PO, axis_source);
}

static void _CWlPointerAxisStop(void* data, void* resource, uint32_t time, enum wl_pointer_axis axis) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.axisStop)
        PO->requests.axisStop(PO, time, axis);
}

static void _CWlPointerAxisDiscrete(void* data, void* resource, enum wl_pointer_axis axis, int32_t discrete) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.axisDiscrete)
        PO->requests.axisDiscrete(PO, axis, discrete);
}

static void _CWlPointerAxisValue120(void* data, void* resource, enum wl_pointer_axis axis, int32_t value120) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.axisValue120)
        PO->requests.axisValue120(PO, axis, value120);
}

static void _CWlPointerAxisRelativeDirection(void* data, void* resource, enum wl_pointer_axis axis, enum wl_pointer_axis_relative_direction direction) {
    const auto PO = (CCWlPointer*)data;
    if (PO && PO->requests.axisRelativeDirection)
        PO->requests.axisRelativeDirection(PO, axis, direction);
}

static const void* _CCWlPointerVTable[] = {
    (void*)_CWlPointerEnter,
    (void*)_CWlPointerLeave,
    (void*)_CWlPointerMotion,
    (void*)_CWlPointerButton,
    (void*)_CWlPointerAxis,
    (void*)_CWlPointerFrame,
    (void*)_CWlPointerAxisSource,
    (void*)_CWlPointerAxisStop,
    (void*)_CWlPointerAxisDiscrete,
    (void*)_CWlPointerAxisValue120,
    (void*)_CWlPointerAxisRelativeDirection,
};

void CCWlPointer::sendSetCursor(uint32_t serial, CCWlSurface* surface, int32_t hotspot_x, int32_t hotspot_y) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, serial, surface ? surface->pResource : nullptr, hotspot_x, hotspot_y);
    proxy;
}

void CCWlPointer::sendRelease() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CWlPointerSetCursorTypes[] = {
    nullptr,
    &wl_surface_interface,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerEnterTypes[] = {
    nullptr,
    &wl_surface_interface,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerLeaveTypes[] = {
    nullptr,
    &wl_surface_interface,
};
static const wl_interface* _CWlPointerMotionTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerButtonTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerAxisTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerAxisSourceTypes[] = {
    nullptr,
};
static const wl_interface* _CWlPointerAxisStopTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerAxisDiscreteTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerAxisValue120Types[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlPointerAxisRelativeDirectionTypes[] = {
    nullptr,
    nullptr,
};

static const wl_message _CWlPointerRequests[] = {
    { "set_cursor", "u?oii", _CWlPointerSetCursorTypes + 0},
    { "release", "3", dummyTypes + 0},
};

static const wl_message _CWlPointerEvents[] = {
    { "enter", "uoff", _CWlPointerEnterTypes + 0},
    { "leave", "uo", _CWlPointerLeaveTypes + 0},
    { "motion", "uff", _CWlPointerMotionTypes + 0},
    { "button", "uuuu", _CWlPointerButtonTypes + 0},
    { "axis", "uuf", _CWlPointerAxisTypes + 0},
    { "frame", "5", dummyTypes + 0},
    { "axis_source", "5u", _CWlPointerAxisSourceTypes + 0},
    { "axis_stop", "5uu", _CWlPointerAxisStopTypes + 0},
    { "axis_discrete", "5ui", _CWlPointerAxisDiscreteTypes + 0},
    { "axis_value120", "8ui", _CWlPointerAxisValue120Types + 0},
    { "axis_relative_direction", "9uu", _CWlPointerAxisRelativeDirectionTypes + 0},
};

const wl_interface wl_pointer_interface = {
    "wl_pointer", 9,
    2, _CWlPointerRequests,
    11, _CWlPointerEvents,
};

CCWlPointer::CCWlPointer(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlPointerVTable, this);
}

CCWlPointer::~CCWlPointer() {
    if (!destroyed)
        sendRelease();
}

void CCWlPointer::setEnter(F<void(CCWlPointer*, uint32_t, wl_proxy*, wl_fixed_t, wl_fixed_t)> handler) {
    requests.enter = handler;
}

void CCWlPointer::setLeave(F<void(CCWlPointer*, uint32_t, wl_proxy*)> handler) {
    requests.leave = handler;
}

void CCWlPointer::setMotion(F<void(CCWlPointer*, uint32_t, wl_fixed_t, wl_fixed_t)> handler) {
    requests.motion = handler;
}

void CCWlPointer::setButton(F<void(CCWlPointer*, uint32_t, uint32_t, uint32_t, enum wl_pointer_button_state)> handler) {
    requests.button = handler;
}

void CCWlPointer::setAxis(F<void(CCWlPointer*, uint32_t, enum wl_pointer_axis, wl_fixed_t)> handler) {
    requests.axis = handler;
}

void CCWlPointer::setFrame(F<void(CCWlPointer*)> handler) {
    requests.frame = handler;
}

void CCWlPointer::setAxisSource(F<void(CCWlPointer*, enum wl_pointer_axis_source)> handler) {
    requests.axisSource = handler;
}

void CCWlPointer::setAxisStop(F<void(CCWlPointer*, uint32_t, enum wl_pointer_axis)> handler) {
    requests.axisStop = handler;
}

void CCWlPointer::setAxisDiscrete(F<void(CCWlPointer*, enum wl_pointer_axis, int32_t)> handler) {
    requests.axisDiscrete = handler;
}

void CCWlPointer::setAxisValue120(F<void(CCWlPointer*, enum wl_pointer_axis, int32_t)> handler) {
    requests.axisValue120 = handler;
}

void CCWlPointer::setAxisRelativeDirection(F<void(CCWlPointer*, enum wl_pointer_axis, enum wl_pointer_axis_relative_direction)> handler) {
    requests.axisRelativeDirection = handler;
}

static void _CWlKeyboardKeymap(void* data, void* resource, enum wl_keyboard_keymap_format format, int32_t fd, uint32_t size) {
    const auto PO = (CCWlKeyboard*)data;
    if (PO && PO->requests.keymap)
        PO->requests.keymap(PO, format, fd, size);
}

static void _CWlKeyboardEnter(void* data, void* resource, uint32_t serial, wl_proxy* surface, wl_array* keys) {
    const auto PO = (CCWlKeyboard*)data;
    if (PO && PO->requests.enter)
        PO->requests.enter(PO, serial, surface, keys);
}

static void _CWlKeyboardLeave(void* data, void* resource, uint32_t serial, wl_proxy* surface) {
    const auto PO = (CCWlKeyboard*)data;
    if (PO && PO->requests.leave)
        PO->requests.leave(PO, serial, surface);
}

static void _CWlKeyboardKey(void* data, void* resource, uint32_t serial, uint32_t time, uint32_t key, enum wl_keyboard_key_state state) {
    const auto PO = (CCWlKeyboard*)data;
    if (PO && PO->requests.key)
        PO->requests.key(PO, serial, time, key, state);
}

static void _CWlKeyboardModifiers(void* data, void* resource, uint32_t serial, uint32_t mods_depressed, uint32_t mods_latched, uint32_t mods_locked, uint32_t group) {
    const auto PO = (CCWlKeyboard*)data;
    if (PO && PO->requests.modifiers)
        PO->requests.modifiers(PO, serial, mods_depressed, mods_latched, mods_locked, group);
}

static void _CWlKeyboardRepeatInfo(void* data, void* resource, int32_t rate, int32_t delay) {
    const auto PO = (CCWlKeyboard*)data;
    if (PO && PO->requests.repeatInfo)
        PO->requests.repeatInfo(PO, rate, delay);
}

static const void* _CCWlKeyboardVTable[] = {
    (void*)_CWlKeyboardKeymap,
    (void*)_CWlKeyboardEnter,
    (void*)_CWlKeyboardLeave,
    (void*)_CWlKeyboardKey,
    (void*)_CWlKeyboardModifiers,
    (void*)_CWlKeyboardRepeatInfo,
};

void CCWlKeyboard::sendRelease() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CWlKeyboardKeymapTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlKeyboardEnterTypes[] = {
    nullptr,
    &wl_surface_interface,
    nullptr,
};
static const wl_interface* _CWlKeyboardLeaveTypes[] = {
    nullptr,
    &wl_surface_interface,
};
static const wl_interface* _CWlKeyboardKeyTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlKeyboardModifiersTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlKeyboardRepeatInfoTypes[] = {
    nullptr,
    nullptr,
};

static const wl_message _CWlKeyboardRequests[] = {
    { "release", "3", dummyTypes + 0},
};

static const wl_message _CWlKeyboardEvents[] = {
    { "keymap", "uhu", _CWlKeyboardKeymapTypes + 0},
    { "enter", "uoa", _CWlKeyboardEnterTypes + 0},
    { "leave", "uo", _CWlKeyboardLeaveTypes + 0},
    { "key", "uuuu", _CWlKeyboardKeyTypes + 0},
    { "modifiers", "uuuuu", _CWlKeyboardModifiersTypes + 0},
    { "repeat_info", "4ii", _CWlKeyboardRepeatInfoTypes + 0},
};

const wl_interface wl_keyboard_interface = {
    "wl_keyboard", 9,
    1, _CWlKeyboardRequests,
    6, _CWlKeyboardEvents,
};

CCWlKeyboard::CCWlKeyboard(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlKeyboardVTable, this);
}

CCWlKeyboard::~CCWlKeyboard() {
    if (!destroyed)
        sendRelease();
}

void CCWlKeyboard::setKeymap(F<void(CCWlKeyboard*, enum wl_keyboard_keymap_format, int32_t, uint32_t)> handler) {
    requests.keymap = handler;
}

void CCWlKeyboard::setEnter(F<void(CCWlKeyboard*, uint32_t, wl_proxy*, wl_array*)> handler) {
    requests.enter = handler;
}

void CCWlKeyboard::setLeave(F<void(CCWlKeyboard*, uint32_t, wl_proxy*)> handler) {
    requests.leave = handler;
}

void CCWlKeyboard::setKey(F<void(CCWlKeyboard*, uint32_t, uint32_t, uint32_t, enum wl_keyboard_key_state)> handler) {
    requests.key = handler;
}

void CCWlKeyboard::setModifiers(F<void(CCWlKeyboard*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t)> handler) {
    requests.modifiers = handler;
}

void CCWlKeyboard::setRepeatInfo(F<void(CCWlKeyboard*, int32_t, int32_t)> handler) {
    requests.repeatInfo = handler;
}

static void _CWlTouchDown(void* data, void* resource, uint32_t serial, uint32_t time, wl_proxy* surface, int32_t id, wl_fixed_t x, wl_fixed_t y) {
    const auto PO = (CCWlTouch*)data;
    if (PO && PO->requests.down)
        PO->requests.down(PO, serial, time, surface, id, x, y);
}

static void _CWlTouchUp(void* data, void* resource, uint32_t serial, uint32_t time, int32_t id) {
    const auto PO = (CCWlTouch*)data;
    if (PO && PO->requests.up)
        PO->requests.up(PO, serial, time, id);
}

static void _CWlTouchMotion(void* data, void* resource, uint32_t time, int32_t id, wl_fixed_t x, wl_fixed_t y) {
    const auto PO = (CCWlTouch*)data;
    if (PO && PO->requests.motion)
        PO->requests.motion(PO, time, id, x, y);
}

static void _CWlTouchFrame(void* data, void* resource) {
    const auto PO = (CCWlTouch*)data;
    if (PO && PO->requests.frame)
        PO->requests.frame(PO);
}

static void _CWlTouchCancel(void* data, void* resource) {
    const auto PO = (CCWlTouch*)data;
    if (PO && PO->requests.cancel)
        PO->requests.cancel(PO);
}

static void _CWlTouchShape(void* data, void* resource, int32_t id, wl_fixed_t major, wl_fixed_t minor) {
    const auto PO = (CCWlTouch*)data;
    if (PO && PO->requests.shape)
        PO->requests.shape(PO, id, major, minor);
}

static void _CWlTouchOrientation(void* data, void* resource, int32_t id, wl_fixed_t orientation) {
    const auto PO = (CCWlTouch*)data;
    if (PO && PO->requests.orientation)
        PO->requests.orientation(PO, id, orientation);
}

static const void* _CCWlTouchVTable[] = {
    (void*)_CWlTouchDown,
    (void*)_CWlTouchUp,
    (void*)_CWlTouchMotion,
    (void*)_CWlTouchFrame,
    (void*)_CWlTouchCancel,
    (void*)_CWlTouchShape,
    (void*)_CWlTouchOrientation,
};

void CCWlTouch::sendRelease() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CWlTouchDownTypes[] = {
    nullptr,
    nullptr,
    &wl_surface_interface,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlTouchUpTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlTouchMotionTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlTouchShapeTypes[] = {
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlTouchOrientationTypes[] = {
    nullptr,
    nullptr,
};

static const wl_message _CWlTouchRequests[] = {
    { "release", "3", dummyTypes + 0},
};

static const wl_message _CWlTouchEvents[] = {
    { "down", "uuoiff", _CWlTouchDownTypes + 0},
    { "up", "uui", _CWlTouchUpTypes + 0},
    { "motion", "uiff", _CWlTouchMotionTypes + 0},
    { "frame", "", dummyTypes + 0},
    { "cancel", "", dummyTypes + 0},
    { "shape", "6iff", _CWlTouchShapeTypes + 0},
    { "orientation", "6if", _CWlTouchOrientationTypes + 0},
};

const wl_interface wl_touch_interface = {
    "wl_touch", 9,
    1, _CWlTouchRequests,
    7, _CWlTouchEvents,
};

CCWlTouch::CCWlTouch(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlTouchVTable, this);
}

CCWlTouch::~CCWlTouch() {
    if (!destroyed)
        sendRelease();
}

void CCWlTouch::setDown(F<void(CCWlTouch*, uint32_t, uint32_t, wl_proxy*, int32_t, wl_fixed_t, wl_fixed_t)> handler) {
    requests.down = handler;
}

void CCWlTouch::setUp(F<void(CCWlTouch*, uint32_t, uint32_t, int32_t)> handler) {
    requests.up = handler;
}

void CCWlTouch::setMotion(F<void(CCWlTouch*, uint32_t, int32_t, wl_fixed_t, wl_fixed_t)> handler) {
    requests.motion = handler;
}

void CCWlTouch::setFrame(F<void(CCWlTouch*)> handler) {
    requests.frame = handler;
}

void CCWlTouch::setCancel(F<void(CCWlTouch*)> handler) {
    requests.cancel = handler;
}

void CCWlTouch::setShape(F<void(CCWlTouch*, int32_t, wl_fixed_t, wl_fixed_t)> handler) {
    requests.shape = handler;
}

void CCWlTouch::setOrientation(F<void(CCWlTouch*, int32_t, wl_fixed_t)> handler) {
    requests.orientation = handler;
}

static void _CWlOutputGeometry(void* data, void* resource, int32_t x, int32_t y, int32_t physical_width, int32_t physical_height, int32_t subpixel, const char* make, const char* model, int32_t transform) {
    const auto PO = (CCWlOutput*)data;
    if (PO && PO->requests.geometry)
        PO->requests.geometry(PO, x, y, physical_width, physical_height, subpixel, make, model, transform);
}

static void _CWlOutputMode(void* data, void* resource, enum wl_output_mode flags, int32_t width, int32_t height, int32_t refresh) {
    const auto PO = (CCWlOutput*)data;
    if (PO && PO->requests.mode)
        PO->requests.mode(PO, flags, width, height, refresh);
}

static void _CWlOutputDone(void* data, void* resource) {
    const auto PO = (CCWlOutput*)data;
    if (PO && PO->requests.done)
        PO->requests.done(PO);
}

static void _CWlOutputScale(void* data, void* resource, int32_t factor) {
    const auto PO = (CCWlOutput*)data;
    if (PO && PO->requests.scale)
        PO->requests.scale(PO, factor);
}

static void _CWlOutputName(void* data, void* resource, const char* name) {
    const auto PO = (CCWlOutput*)data;
    if (PO && PO->requests.name)
        PO->requests.name(PO, name);
}

static void _CWlOutputDescription(void* data, void* resource, const char* description) {
    const auto PO = (CCWlOutput*)data;
    if (PO && PO->requests.description)
        PO->requests.description(PO, description);
}

static const void* _CCWlOutputVTable[] = {
    (void*)_CWlOutputGeometry,
    (void*)_CWlOutputMode,
    (void*)_CWlOutputDone,
    (void*)_CWlOutputScale,
    (void*)_CWlOutputName,
    (void*)_CWlOutputDescription,
};

void CCWlOutput::sendRelease() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}
static const wl_interface* _CWlOutputGeometryTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlOutputModeTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlOutputScaleTypes[] = {
    nullptr,
};
static const wl_interface* _CWlOutputNameTypes[] = {
    nullptr,
};
static const wl_interface* _CWlOutputDescriptionTypes[] = {
    nullptr,
};

static const wl_message _CWlOutputRequests[] = {
    { "release", "3", dummyTypes + 0},
};

static const wl_message _CWlOutputEvents[] = {
    { "geometry", "iiiiissi", _CWlOutputGeometryTypes + 0},
    { "mode", "uiii", _CWlOutputModeTypes + 0},
    { "done", "2", dummyTypes + 0},
    { "scale", "2i", _CWlOutputScaleTypes + 0},
    { "name", "4s", _CWlOutputNameTypes + 0},
    { "description", "4s", _CWlOutputDescriptionTypes + 0},
};

const wl_interface wl_output_interface = {
    "wl_output", 4,
    1, _CWlOutputRequests,
    6, _CWlOutputEvents,
};

CCWlOutput::CCWlOutput(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlOutputVTable, this);
}

CCWlOutput::~CCWlOutput() {
    if (!destroyed)
        sendRelease();
}

void CCWlOutput::setGeometry(F<void(CCWlOutput*, int32_t, int32_t, int32_t, int32_t, int32_t, const char*, const char*, int32_t)> handler) {
    requests.geometry = handler;
}

void CCWlOutput::setMode(F<void(CCWlOutput*, enum wl_output_mode, int32_t, int32_t, int32_t)> handler) {
    requests.mode = handler;
}

void CCWlOutput::setDone(F<void(CCWlOutput*)> handler) {
    requests.done = handler;
}

void CCWlOutput::setScale(F<void(CCWlOutput*, int32_t)> handler) {
    requests.scale = handler;
}

void CCWlOutput::setName(F<void(CCWlOutput*, const char*)> handler) {
    requests.name = handler;
}

void CCWlOutput::setDescription(F<void(CCWlOutput*, const char*)> handler) {
    requests.description = handler;
}

static const void* _CCWlRegionVTable[] = {
};

void CCWlRegion::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCWlRegion::sendAdd(int32_t x, int32_t y, int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y, width, height);
    proxy;
}

void CCWlRegion::sendSubtract(int32_t x, int32_t y, int32_t width, int32_t height) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y, width, height);
    proxy;
}
static const wl_interface* _CWlRegionAddTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
static const wl_interface* _CWlRegionSubtractTypes[] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};

static const wl_message _CWlRegionRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "add", "iiii", _CWlRegionAddTypes + 0},
    { "subtract", "iiii", _CWlRegionSubtractTypes + 0},
};

const wl_interface wl_region_interface = {
    "wl_region", 1,
    3, _CWlRegionRequests,
    0, nullptr,
};

CCWlRegion::CCWlRegion(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlRegionVTable, this);
}

CCWlRegion::~CCWlRegion() {
    if (!destroyed)
        sendDestroy();
}

static const void* _CCWlSubcompositorVTable[] = {
};

void CCWlSubcompositor::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

wl_proxy* CCWlSubcompositor::sendGetSubsurface(CCWlSurface* surface, CCWlSurface* parent) {
    if (!pResource)
        return nullptr;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, &wl_subsurface_interface, wl_proxy_get_version((wl_proxy*)pResource), 0, nullptr, surface ? surface->pResource : nullptr, parent ? parent->pResource : nullptr);

    return proxy;
}
static const wl_interface* _CWlSubcompositorGetSubsurfaceTypes[] = {
    &wl_subsurface_interface,
    &wl_surface_interface,
    &wl_surface_interface,
};

static const wl_message _CWlSubcompositorRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "get_subsurface", "noo", _CWlSubcompositorGetSubsurfaceTypes + 0},
};

const wl_interface wl_subcompositor_interface = {
    "wl_subcompositor", 1,
    2, _CWlSubcompositorRequests,
    0, nullptr,
};

CCWlSubcompositor::CCWlSubcompositor(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlSubcompositorVTable, this);
}

CCWlSubcompositor::~CCWlSubcompositor() {
    if (!destroyed)
        sendDestroy();
}

static const void* _CCWlSubsurfaceVTable[] = {
};

void CCWlSubsurface::sendDestroy() {
    if (!pResource)
        return;
    destroyed = true;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 0, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 1);
    proxy;
}

void CCWlSubsurface::sendSetPosition(int32_t x, int32_t y) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 1, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, x, y);
    proxy;
}

void CCWlSubsurface::sendPlaceAbove(CCWlSurface* sibling) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 2, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, sibling ? sibling->pResource : nullptr);
    proxy;
}

void CCWlSubsurface::sendPlaceBelow(CCWlSurface* sibling) {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 3, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0, sibling ? sibling->pResource : nullptr);
    proxy;
}

void CCWlSubsurface::sendSetSync() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 4, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}

void CCWlSubsurface::sendSetDesync() {
    if (!pResource)
        return;

    auto proxy = wl_proxy_marshal_flags((wl_proxy*)pResource, 5, nullptr, wl_proxy_get_version((wl_proxy*)pResource), 0);
    proxy;
}
static const wl_interface* _CWlSubsurfaceSetPositionTypes[] = {
    nullptr,
    nullptr,
};
static const wl_interface* _CWlSubsurfacePlaceAboveTypes[] = {
    &wl_surface_interface,
};
static const wl_interface* _CWlSubsurfacePlaceBelowTypes[] = {
    &wl_surface_interface,
};

static const wl_message _CWlSubsurfaceRequests[] = {
    { "destroy", "", dummyTypes + 0},
    { "set_position", "ii", _CWlSubsurfaceSetPositionTypes + 0},
    { "place_above", "o", _CWlSubsurfacePlaceAboveTypes + 0},
    { "place_below", "o", _CWlSubsurfacePlaceBelowTypes + 0},
    { "set_sync", "", dummyTypes + 0},
    { "set_desync", "", dummyTypes + 0},
};

const wl_interface wl_subsurface_interface = {
    "wl_subsurface", 1,
    6, _CWlSubsurfaceRequests,
    0, nullptr,
};

CCWlSubsurface::CCWlSubsurface(wl_proxy* resource) {
    pResource = resource;

    if (!pResource)
        return;

    wl_proxy_add_listener(pResource, (void (**)(void))&_CCWlSubsurfaceVTable, this);
}

CCWlSubsurface::~CCWlSubsurface() {
    if (!destroyed)
        sendDestroy();
}

#undef F
