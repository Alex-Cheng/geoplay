#include "UIBridge.h"
#include <iostream>

UIBridge::UIBridge() {}

UIBridge::~UIBridge() {}

void UIBridge::SendMessageToRenderer(const std::string& message) {
    // 输出收到的消息
    std::cout << "Received message: " << message << std::endl;

    // 处理消息，触发渲染相关操作（比如创建模型）
}

bool UIBridge::OnProcessMessageReceived(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefProcessMessage::MessageType type) {
    // 接收来自 React 的消息并做出反应
    // 这里只是简单的处理 `createCube` 消息
    if (type == CefProcessMessage::MessageType::kMessageTypeRequest) {
        CefProcessMessage* message = frame->GetProcessMessage();
        if (message->GetName() == "createCube") {
            // 调用渲染逻辑来创建立方体
            SendMessageToRenderer("createCube");
            return true;
        }
    }
    return false;
}
