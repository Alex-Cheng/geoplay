import React, { useState } from 'react';

export const SidePanel = () => {
  const [shapeType, setShapeType] = useState('cube');
  
  const handleShapeChange = (event: React.ChangeEvent<HTMLSelectElement>) => {
    setShapeType(event.target.value);
    window.cefAPI.sendMessage("updateShape", { shape: event.target.value });
  };

  return (
    <div style={{ width: '200px', padding: '10px' }}>
      <h3>Model Properties</h3>
      <div>
        <label>Shape Type: </label>
        <select value={shapeType} onChange={handleShapeChange}>
          <option value="cube">Cube</option>
          <option value="sphere">Sphere</option>
          <option value="cone">Cone</option>
        </select>
      </div>
    </div>
  );
};
