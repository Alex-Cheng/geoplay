import React from 'react';
import { RibbonBar } from './components/RibbonBar';
import { SidePanel } from './components/SidePanel';
import { RendererPanel } from './components/RendererPanel';

export const App = () => {
  return (
    <div style={{ display: 'flex', flexDirection: 'column', height: '100vh' }}>
      <RibbonBar />
      <div style={{ display: 'flex', flex: 1 }}>
        <SidePanel />
        <RendererPanel />
      </div>
    </div>
  );
};