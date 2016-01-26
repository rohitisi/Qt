// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BitmapPattern_h
#define BitmapPattern_h

#include "platform/graphics/BitmapPatternBase.h"

namespace blink {

class PLATFORM_EXPORT BitmapPattern : public BitmapPatternBase {
public:
    static PassRefPtr<BitmapPattern> create(PassRefPtr<Image> tileImage, RepeatMode repeatMode)
    {
        return adoptRef(new BitmapPattern(tileImage, repeatMode));
    }

    virtual ~BitmapPattern() { }

protected:
    virtual PassRefPtr<SkShader> createShader() override;

    virtual SkImageInfo getBitmapInfo() override;
    virtual void drawBitmapToCanvas(SkCanvas&, SkPaint&) override;

private:
    BitmapPattern(PassRefPtr<Image>, RepeatMode);

    RefPtr<NativeImageSkia> m_tileImage;
};

} // namespace

#endif