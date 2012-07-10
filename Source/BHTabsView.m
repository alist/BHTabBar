#import "BHTabsView.h"
#import "BHTabStyle.h"

@implementation BHTabsView

@synthesize tabViews;
@synthesize style;

- (void)layoutSubviews {
  float N = [self.tabViews count];
  
  CGFloat W = self.frame.size.width / N;
  NSInteger overlap = W * self.style.overlapAsPercentageOfTabWidth;
  CGFloat width = self.frame.size.width;
  W = (width + (float)overlap * (N-1)) / N;
  
  NSUInteger tabIndex = 0;
  
  for (UIView *tabView in self.tabViews) {
    CGRect tabFrame = CGRectMake(tabIndex * W,
                                 self.style.tabsViewHeight - self.style.tabHeight - self.style.tabBarHeight,
                                 W, self.style.tabHeight);
    
    if (tabIndex > 0)
      tabFrame.origin.x -= tabIndex * overlap;
    
    tabView.frame = tabFrame;
    
    tabIndex++;
  }
}


@end
