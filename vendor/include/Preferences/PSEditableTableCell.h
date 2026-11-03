#import "PSTableCell.h"

@interface PSEditableTableCell : PSTableCell {
	id _userInfo;
	SEL _targetSetter;
	id _realTarget;
}

// Private editing callbacks omitted from the public header set.
- (id)textField;
- (void)_setValueChanged;

- (void)controlChanged:(id)changed;
- (void)setValueChangedOnReturn;
- (void)setValueChangedTarget:(id)target action:(SEL)action userInfo:(id)info;

@end
