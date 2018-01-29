//
//  NodeTreeView.h
//  TreeNodeStructure
//
//  Created by ccSunday on 2018/1/23.
//  Copyright © 2018年 ccSunday. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NodeModelProtocol.h"
#import "NodeViewProtocol.h"

typedef NS_ENUM(NSUInteger,NodeTreeViewStyle)
{
    NodeTreeViewStyleBreadcrumbs,          //面包屑形式
    NodeTreeViewStyleExpansion              //展开形式
};

@class NodeTreeView;
@protocol NodeTreeViewDelegate
@required
/**
 返回对应节点下的视图：视图可以遵循NodeViewProtocol协议，让view具有一些统一的行为>
 一种node对应一种nodeView
 
 @param node node节点
 @return node视图
 */
- (id<NodeViewProtocol>_Nonnull)nodeTreeView:(NodeTreeView *_Nonnull)treeView viewForNode:(id<NodeModelProtocol>_Nonnull)node;

@optional
/**
 点击事件回调

 @param treeView 树
 @param node 节点模型
 */
- (void)nodeTreeView:(NodeTreeView *_Nonnull)treeView didSelectNode:(id<NodeModelProtocol>_Nonnull)node;

@end

@interface NodeTreeView : UIView
/**
 开启手动刷新,默认是自动刷新
 */
@property (nonatomic, assign,getter=isManualRefresh) BOOL manualRefresh;
/**
 代理
 */
@property (nonatomic, assign) id<NodeTreeViewDelegate>_Nonnull treeDelegate;


/**
 初始化方法

 @param frame frame
 @param style 展现形式
 @return treeView实例
 */
- (instancetype _Nullable )initWithFrame:(CGRect)frame treeViewStyle:(NodeTreeViewStyle)style;

/**
 刷新node节点对应的树
 */
- (void)reloadTreeViewWithNode:(id<NodeModelProtocol>_Nonnull)node;;
/**
 刷新node节点对应的树，可以指定动画展开的方式

 @param node  node节点

 */
- (void)reloadTreeViewWithNode:(id<NodeModelProtocol>_Nonnull)node
                  RowAnimation:(UITableViewRowAnimation)animation;
/**
 返回对应节点的view

 @param node 节点
 @return 该节点对应的nodeview
 */
- (id<NodeViewProtocol>_Nonnull)nodeViewForNode:(id<NodeModelProtocol>_Nonnull)node;

@end