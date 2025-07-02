import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';  // 引入样式文件

// 入口组件
import App from './App';

// 渲染应用
ReactDOM.render(
  <React.StrictMode>
    <App />
  </React.StrictMode>,
  document.getElementById('root')  // 挂载到 index.html 中的 id="root" 元素
);
