// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BatteryDispatcher_h
#define BatteryDispatcher_h

#include "core/frame/PlatformEventDispatcher.h"
#include "modules/battery/BatteryManager.h"
#include "modules/battery/BatteryStatus.h"
#include "public/platform/WebBatteryStatusListener.h"

namespace blink {

class WebBatteryStatus;

class BatteryDispatcher final : public GarbageCollectedFinalized<BatteryDispatcher>, public PlatformEventDispatcher, public WebBatteryStatusListener {
    USING_GARBAGE_COLLECTED_MIXIN(BatteryDispatcher);
public:
    static BatteryDispatcher& instance();
    virtual ~BatteryDispatcher();

    BatteryStatus* latestData();

    // Inherited from WebBatteryStatusListener.
    virtual void updateBatteryStatus(const WebBatteryStatus&) override;

    virtual void trace(Visitor*) override;

private:
    BatteryDispatcher();

    // Inherited from PlatformEventDispatcher.
    virtual void startListening() override;
    virtual void stopListening() override;

    Member<BatteryStatus> m_batteryStatus;
};

} // namespace blink

#endif // BatteryDispatcher_h
