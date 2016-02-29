//
//  AFNetworkingRequest.h
//  网络请求
//
//  Created by Macbook Pro on 16/2/29.
//  Copyright © 2016年 Macbook Pro. All rights reserved.
//

/**
 要使用常规的AFN网络访问
 
 1. AFHTTPRequestOperationManager *manager = [AFHTTPRequestOperationManager manager];
 
 所有的网络请求,均有manager发起
 
 2. 需要注意的是,默认提交请求的数据是二进制的,返回格式是JSON
 
 1> 如果提交数据是JSON的,需要将请求格式设置为AFJSONRequestSerializer
 2> 如果返回格式不是JSON的,
 
 3. 请求格式
 
 AFHTTPRequestSerializer            二进制格式
 AFJSONRequestSerializer            JSON
 AFPropertyListRequestSerializer    PList(是一种特殊的XML,解析起来相对容易)
 
 4. 返回格式
 
 AFHTTPResponseSerializer           二进制格式
 AFJSONResponseSerializer           JSON
 AFXMLParserResponseSerializer      XML,只能返回XMLParser,还需要自己通过代理方法解析
 AFXMLDocumentResponseSerializer (Mac OS X)
 AFPropertyListResponseSerializer   PList
 AFImageResponseSerializer          Image
 AFCompoundResponseSerializer       组合
 */

#import <Foundation/Foundation.h>
#import "AFNetworking.h"
@interface AFNetworkingRequest : NSObject

/**检测网路状态**/
+ (void)netWorkStatus;

/**
 *JSON方式获取数据
 *urlStr:获取数据的url地址
 *
 */
+ (void)JSONDataWithUrl:(NSString *)url success:(void (^)(id json))success fail:(void (^)())fail;

/**
 *xml方式获取数据
 *urlStr:获取数据的url地址
 *
 */
+ (void)XMLDataWithUrl:(NSString *)urlStr success:(void (^)(id xml))success fail:(void (^)())fail;

/**
 *JSON方式post提交数据
 *urlStr:服务器地址
 *parameters:提交的内容参数
 *
 */
+ (void)postJSONWithUrl:(NSString *)urlStr parameters:(id)parameters success:(void (^)(id responseObject))success fail:(void (^)())fail;

/**
 *Session下载文件
 *urlStr :   下载文件的url地址
 *
 */
+ (void)sessionDownloadWithUrl:(NSString *)urlStr success:(void (^)(NSURL *fileURL))success fail:(void (^)())fail;

/**
 *文件上传,自己定义文件名
 *urlStr:    需要上传的服务器url
 *fileURL:   需要上传的本地文件URL
 *fileName:  文件在服务器上以什么名字保存
 *fileTye:   文件类型
 *
 */
+ (void)postUploadWithUrl:(NSString *)urlStr fileUrl:(NSURL *)fileURL fileName:(NSString *)fileName fileType:(NSString *)fileTye success:(void (^)(id responseObject))success fail:(void (^)())fail;

/**
 *文件上传,文件名由服务器端决定
 *urlStr:    需要上传的服务器url
 *fileURL:   需要上传的本地文件URL
 *
 */
+ (void)postUploadWithUrl:(NSString *)urlStr fileUrl:(NSURL *)fileURL success:(void (^)(id responseObject))success fail:(void (^)())fail;

/**
 *  上传带图片的内容，允许多张图片上传（URL）POST
 *
 *  @param url                 网络请求地址
 *  @param images              要上传的图片数组（注意数组内容需是图片）
 *  @param parameter           图片数组对应的参数
 *  @param parameters          其他参数字典
 *  @param ratio               图片的压缩比例（0.0~1.0之间）
 *  @param succeedBlock        成功的回调
 *  @param failedBlock         失败的回调
 *  @param uploadProgressBlock 上传进度的回调
 */
+(void)startMultiPartUploadTaskWithURL:(NSString *)url
                           imagesArray:(NSArray *)images
                     parameterOfimages:(NSString *)parameter
                        parametersDict:(NSDictionary *)parameters
                      compressionRatio:(float)ratio
                          succeedBlock:(void(^)(id operation, id responseObject))succeedBlock
                           failedBlock:(void(^)(id operation, NSError *error))failedBlock
                   uploadProgressBlock:(void(^)(float uploadPercent,long long totalBytesWritten,long long totalBytesExpectedToWrite))uploadProgressBlock;

@end
