import { CommandBar, ICommandBarItemProps } from '@fluentui/react';

const items: ICommandBarItemProps[] = [
  { key: 'new', text: 'New', iconProps: { iconName: 'Add' }, onClick: () => alert('Create New') },
  { key: 'open', text: 'Open', iconProps: { iconName: 'OpenFile' }, onClick: () => alert('Open File') },
];

export const RibbonBar = () => {
  return <CommandBar items={items} />;
};
