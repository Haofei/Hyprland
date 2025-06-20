#pragma once

#include "IHyprWindowDecoration.hpp"
#include "../../devices/IPointer.hpp"
#include <vector>
#include "../Texture.hpp"
#include <string>
#include "../../helpers/memory/Memory.hpp"

class CTitleTex {
  public:
    CTitleTex(PHLWINDOW pWindow, const Vector2D& bufferSize, const float monitorScale);
    ~CTitleTex() = default;

    SP<CTexture> m_texActive;
    SP<CTexture> m_texInactive;
    SP<CTexture> m_texLockedActive;
    SP<CTexture> m_texLockedInactive;
    std::string  m_content;

    PHLWINDOWREF m_windowOwner;
};

void refreshGroupBarGradients();

class CHyprGroupBarDecoration : public IHyprWindowDecoration {
  public:
    CHyprGroupBarDecoration(PHLWINDOW);
    virtual ~CHyprGroupBarDecoration() = default;

    virtual SDecorationPositioningInfo getPositioningInfo();

    virtual void                       onPositioningReply(const SDecorationPositioningReply& reply);

    virtual void                       draw(PHLMONITOR, float const& a);

    virtual eDecorationType            getDecorationType();

    virtual void                       updateWindow(PHLWINDOW);

    virtual void                       damageEntire();

    virtual bool                       onInputOnDeco(const eInputType, const Vector2D&, std::any = {});

    virtual eDecorationLayer           getDecorationLayer();

    virtual uint64_t                   getDecorationFlags();

    virtual std::string                getDisplayName();

  private:
    CBox                      m_assignedBox = {0};

    PHLWINDOWREF              m_window;

    std::vector<PHLWINDOWREF> m_dwGroupMembers;

    float                     m_barWidth;
    float                     m_barHeight;

    bool                      m_bLastVisibilityStatus = true;

    CTitleTex*                textureFromTitle(const std::string&);
    void                      invalidateTextures();

    CBox                      assignedBoxGlobal();
    bool                      visible();

    bool                      onBeginWindowDragOnDeco(const Vector2D&);
    bool                      onEndWindowDragOnDeco(const Vector2D&, PHLWINDOW);
    bool                      onMouseButtonOnDeco(const Vector2D&, const IPointer::SButtonEvent&);
    bool                      onScrollOnDeco(const Vector2D&, const IPointer::SAxisEvent);

    struct STitleTexs {
        // STitleTexs*                            overriden = nullptr; // TODO: make shit shared in-group to decrease VRAM usage.
        std::vector<UP<CTitleTex>> titleTexs;
    } m_titleTexs;
};
