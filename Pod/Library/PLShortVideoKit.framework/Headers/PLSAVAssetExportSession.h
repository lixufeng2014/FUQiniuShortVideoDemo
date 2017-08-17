//
//  PLSAVAssetExportSession.h
//  PLShortVideoKit
//
//  Created by suntongmian on 2017/7/11.
//  Copyright © 2017年 Pili Engineering, Qiniu Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "PLSTypeDefines.h"


@class PLSEditAudio;
@class PLSAVAssetExportSession;

@protocol PLSAVAssetExportSessionDelegate <NSObject>

/**
 @abstract 输出视频文件的视频数据，用来做滤镜处理
 
 @since      v1.1.0
 */
- (CVPixelBufferRef __nonnull)assetExportSession:(PLSAVAssetExportSession *__nonnull)assetExportSession didOutputPixelBuffer:(CVPixelBufferRef __nonnull)pixelBuffer;

@end

@interface PLSAVAssetExportSession : NSObject

/**
 @abstract 操作视频段的代理
 
 @since      v1.1.0
 */
@property (weak, nonatomic) __nullable id<PLSAVAssetExportSessionDelegate> delegate;

/**
 @property   delegateQueue
 @abstract   触发代理对象回调时所在的任务队列。
 
 @discussion 默认情况下该值为 nil，此时代理方法都会通过 main queue 异步执行回调。如果你期望可以所有的回调在自己创建或者其他非主线程调用，
 可以设置改 delegateQueue 属性。
 
 @see        PLSAVAssetExportSessionDelegate
 @see        delegate
 
 @since      v1.1.0
 */
@property (strong, nonatomic) dispatch_queue_t __nullable delegateQueue;


/**
 @brief 实例初始化方法
 
 @since      v1.1.0
 */
- (instancetype _Nullable )initWithAsset:(AVAsset *_Nullable)asset;

/**
 @brief 视频导出的文件类型，默认为 AVFileTypeMPEG4
 
 @since      v1.1.0
 */
@property (strong, nonatomic) NSString * _Nullable outputFileType;

/**
 @brief 视频导出的路径
 
 @since      v1.1.0
 */
@property (strong, nonatomic) NSURL * _Nullable outputURL;

/**
 @brief 是否设置便于网络环境下的传输，默认为 YES
 
 @since      v1.1.0
 */
@property (assign, nonatomic) BOOL shouldOptimizeForNetworkUse;

/**
 @brief 视频导出的设置信息
 
 @since      v1.1.0
 */
@property (strong, nonatomic) NSDictionary * _Nullable outputSettings;

/**
 @brief 视频导出的进度
 
 @since      v1.1.0
 */
@property (nonatomic, readonly) float progress;

/**
 @abstract 视频导出完成的 block
 
 @since      v1.1.0
 */
@property (copy, nonatomic) void(^ _Nullable completionBlock)(NSURL * _Nullable url);

/**
 @abstract 视频导出失败的 block
 
 @since      v1.1.0
 */
@property (copy, nonatomic) void(^ _Nullable failureBlock)(NSError* _Nullable error);

/**
 @abstract 视频导出进度的 block，可在该 block 中刷新导出进度条 UI
 
 @since      v1.1.0
 */
@property (copy, nonatomic) void(^ _Nullable processingBlock)(float progress);

/**
 @brief 异步进行视频导出
 
 @since      v1.1.0
 */
- (void)exportAsynchronously;

/**
 @brief 取消视频导出
 
 @since      v1.1.0
 */
- (void)cancelExport;

@end

