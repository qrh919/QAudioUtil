//
//  NSString+Extension.m
//  QAudioUtil
//
//  Created by qrh on 2018/3/10.
//  Copyright © 2018年 qrh. All rights reserved.
//

#import "NSString+Extension.h"
#import <CommonCrypto/CommonDigest.h>

@implementation NSString (Extension)

- (NSString*)MD5String
{
    
    if (self == nil || [self length] == 0)
        return nil;
    
    const char* value = [self UTF8String];
    
    unsigned char outputBuffer[CC_MD5_DIGEST_LENGTH];
    CC_MD5(value, (CC_LONG)strlen(value), outputBuffer);
    
    NSMutableString* outputString = [[NSMutableString alloc] initWithCapacity:CC_MD5_DIGEST_LENGTH * 2];
    for (NSInteger count = 0; count < CC_MD5_DIGEST_LENGTH; count++) {
        [outputString appendFormat:@"%02x", outputBuffer[count]];
    }
    
    return [outputString uppercaseString];
}

@end
