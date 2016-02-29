//
//  HTTPRequest.h
//  网络请求
//
//  Created by Macbook Pro on 16/2/29.
//  Copyright © 2016年 Macbook Pro. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface HTTPRequest : NSObject
+ (void)httpRequestWithURL:(NSString *)urlString
                    params:(NSDictionary *)params
                httpMethod:(NSString *)method
              succeedBlock:(void(^)(id responseObj))succeedBlock
                 failBlock:(void(^)(NSHTTPURLResponse *responseObj))failBlock;

@end
