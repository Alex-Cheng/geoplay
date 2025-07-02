import { defineConfig } from 'vite';
import react from '@vitejs/plugin-react';

export default defineConfig({
  plugins: [react()],
  root: './',  // 默认根目录是项目的根目录
  publicDir: 'public',  // 确保 public 目录是静态资源目录
  build: {
    outDir: 'build',  // 构建输出目录
  },
});
