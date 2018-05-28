//
//  QMP3Recorder.h
//  QAudioUtil
//
//  Created by qrh on 2018/3/10.
//  Copyright © 2018年 qrh. All rights reserved.

//  MP3格式录音 将PMC文件格式通过lame转为mp3格式
//  lame 源码地址 https://sourceforge.net/projects/lame/files/lame/
//  lame 编译工具 https://github.com/kewlbear/lame-ios-build

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol QRecorderDelegate <NSObject>

/**
 开始转换
 */
- (void)beginConvert;

/**
 录音失败
 */
- (void)failRecord;

/**
 转换结束
 
 @param fileName 转换后存储在本地的文件路径 可进行上传到服务器
 */
- (void)endConvertWithMP3FileName:(NSString *)fileName;


/**
 音频信号量变化
 
 @param singnalPower 变化的值
 */
- (void)recordSignalPowerDidChange:(CGFloat)singnalPower;

@end

@interface QMP3Recorder : NSObject

@property (nonatomic, weak) id<QRecorderDelegate> delegate;


/**
 MP3 录音是缓存的文件存放路径
 
 @return path
 */
+ (NSString *)mp3CachePathWithFileName:(NSString *)fileName;

/**
 初始化
 
 @param delegate 委托
 @return self
 */
- (id)initWithDelegate:(id<QRecorderDelegate>)delegate;

/**
 开始录音
 */
- (void)startRecord;

/**
 停止录音
 */
- (void)stopRecord;

/**
 取消录音
 */
- (void)cancelRecord;
@end
