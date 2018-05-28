//
//  QAVAudioPlayer.h
//  QAudioUtil
//
//  Created by qrh on 2018/3/10.
//  Copyright © 2018年 qrh. All rights reserved.
//  语音播放
//  流程：根据地址先下载到本地 documents/com.qrh.Chat.audioCache目录下
//  传入URLString,index->检测是否有正在加载,正在播放的音频(停止加载,停止播放)->检查URLString是本地还是网络路径(网络路径下载到本地,并且缓存到本地目录下)->开始播放加载到的audioData->播放结束

#import <Foundation/Foundation.h>

/**
 *  录音消息的状态
 */
typedef NS_ENUM(NSUInteger, QVoiceMessagePlayState){
    /**< 未播放状态 */
    QVoiceMessagePlayState_Normal,
    /**< 正在下载中 */
    QVoiceMessagePlayState_Downloading,
    /**< 正在播放 */
    QVoiceMessagePlayState_Playing,
    /**< 播放被取消 */
    QVoiceMessagePlayState_Cancel,
    /**< 结束 */
    QVoiceMessagePlayState_End
};


@interface QAVAudioPlayer : NSObject
/**
 音频播放地址
 */
@property (nonatomic, copy) NSString *URLString;

/**
 *  identifier -> 主要作用是提供记录,用来控制对应的tableViewCell的状态
 */
@property (nonatomic, copy) NSString *identifier;

/**
 *  当前播放器播放的状态,当tableView滚动时,匹配index来设置对应的audioPlayerState
 */
@property (nonatomic, assign) QVoiceMessagePlayState audioPlayerState;


/**
 单例
 
 @return self
 */
+ (instancetype)sharePlayer;


/**
 播放
 
 @param URLString 音频地址 支持本地和url
 @param identifier 播放的标识符
 */
- (void)playAudioWithURLString:(NSString *)URLString identifier:(NSString *)identifier;


/**
 停止播放
 */
- (void)stopAudioPlayer;


/**
 取消播放
 */
- (void)cleanAudioCache;

/**
 重置播放器
 */
- (void)resetAudioPlayer;

@end
