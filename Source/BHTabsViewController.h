#import <UIKit/UIKit.h>
#import "BHTabView.h"

@class BHTabsViewController;
@class BHTabsFooterView;
@class BHTabStyle;
@class BHTabsView;

@protocol BHTabsViewControllerDelegate <NSObject>
@optional

- (BOOL)shouldMakeTabCurrentAtIndex:(NSUInteger)index tabBarController:(BHTabsViewController *)tabBarController;

- (void)didMakeTabCurrentAtIndex:(NSUInteger)index
                tabBarController:(BHTabsViewController *)tabBarController;

@end

@interface BHTabsViewController : UIViewController <BHTabViewDelegate> {
  NSArray *tabNames;
  UIView *__weak contentView;
  BHTabsView *tabsContainerView;
  BHTabsFooterView *footerView;
  BHTabStyle *tabStyle;
  NSUInteger currentTabIndex;
  id <BHTabsViewControllerDelegate> __unsafe_unretained delegate;
}

@property (nonatomic, unsafe_unretained) id <BHTabsViewControllerDelegate> delegate;
@property (nonatomic, weak, readonly) UIView *contentView;
@property (nonatomic, strong) BHTabStyle *style;

-(NSUInteger) currentTabIndex;

-(id)initWithTabNames:(NSArray*)tabNames style:(BHTabStyle *)style;

@end
