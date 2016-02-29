//
//  HTTPRequest.m
//  网络请求
//
//  Created by Macbook Pro on 16/2/29.
//  Copyright © 2016年 Macbook Pro. All rights reserved.
//

#import "HTTPRequest.h"

@implementation HTTPRequest

+ (void)httpRequestWithURL:(NSString *)urlString
                    params:(NSDictionary *)params
                httpMethod:(NSString *)method
              succeedBlock:(void(^)(id responseObj))succeedBlock
                 failBlock:(void(^)(NSHTTPURLResponse *responseObj))failBlock{
    
    NSURL *url = [NSURL URLWithString:urlString];
    NSString *paramsString = [self paramsStringWithParams:params];
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:method];
    [request setTimeoutInterval:60];
    if ([method isEqualToString:@"GET"]) {
        NSString *separe = url.query?@"&":@"?";
        NSString *fullString = [NSString stringWithFormat:@"%@%@%@",url,separe,paramsString];
        NSURL *fullURL = [NSURL URLWithString:fullString];
        [request setURL:fullURL];
    }else{
        [request setHTTPBody:[paramsString dataUsingEncoding:NSUTF8StringEncoding]];
    }
    NSOperationQueue *queue = [NSOperationQueue mainQueue];
    [NSURLConnection sendAsynchronousRequest:request
                                       queue:queue
                           completionHandler:^(NSURLResponse *response, NSData *data, NSError *connectionError) {
                               if (data) {
                                   id responsObj = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:nil];
                                   succeedBlock(responsObj);
                               }
                               if (connectionError) {
                                   failBlock((NSHTTPURLResponse*)response);
                               }
                           }];
    
    
}
+(NSString*)paramsStringWithParams:(NSDictionary*)params{
    
    NSMutableString *paramsString = [[NSMutableString alloc]init];
    
    for (NSString *key in params) {
        
        [paramsString appendFormat:@"%@=%@",key,[params objectForKey:key]];
        
        if (key != [[params allKeys] lastObject]) {
            
            [paramsString appendString:@"&"];
        }
    }
    
    return paramsString;
}

@end
