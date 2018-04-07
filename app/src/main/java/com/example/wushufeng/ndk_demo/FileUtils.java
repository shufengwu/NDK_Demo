package com.example.wushufeng.ndk_demo;

/**
 * Created by wushufeng on 2018/4/7.
 */

public class FileUtils {
    static {
        System.loadLibrary("file-lib");
    }

    /**
     * 拆分文件
     */
    public native static void split(String path,String path_pattern,int count);


    /**
     * 合并文件
     */
    public native static void merge(String path_pattern,int count,String merge_path);
}
