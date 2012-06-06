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
  UIView *contentView;
  BHTabsView *tabsContainerView;
  BHTabsFooterView *footerView;
  BHTabStyle *tabStyle;
  NSUInteger currentTabIndex;
  id <BHTabsViewControllerDelegate> delegate;
}

@property (nonatomic, assign) id <BHTabsViewControllerDelegate> delegate;
@property (nonatomic, assign, readonly) UIView *contentView;
@property (nonatomic, retain) BHTabStyle *style;

-(id)initWithTabNames:(NSArray*)tabNames style:(BHTabStyle *)style;

@end
