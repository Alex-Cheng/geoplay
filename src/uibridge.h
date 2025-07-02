#ifndef UIBRIDGE_H
#define UIBRIDGE_H

#include "cef_browser.h"  // 包含 CEF 的头文件

class UIBridge : public CefApp {
public:
    UIBridge();
    ~UIBridge();

    // 处理来自 UI 的消息
    void SendMessageToRenderer(const std::string& message);

    // 重载 CEF 消息接收函数
    bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessMessage::MessageType type) override;

private:
    IMPLEMENT_REFCOUNTING(UIBridge);
};

#endif // UIBRIDGE_H
