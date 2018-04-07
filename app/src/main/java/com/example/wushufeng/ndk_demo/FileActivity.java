package com.example.wushufeng.ndk_demo;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import java.io.File;

public class FileActivity extends AppCompatActivity implements View.OnClickListener {

    private Button btnSpilt;
    private Button btnMerge;
    private String SD_CARD_PATH;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_file);
        btnSpilt = findViewById(R.id.btn_spilt);
        btnSpilt.setOnClickListener(this);
        btnMerge = findViewById(R.id.btn_merge);
        btnMerge.setOnClickListener(this);
        SD_CARD_PATH = Environment.getExternalStorageDirectory().getAbsolutePath();

    }

    private void spilt() {
        String path = SD_CARD_PATH + File.separator + "涛声依旧.mp3";
        String path_pattern = SD_CARD_PATH + File.separator + "涛声依旧_%d.mp3";
        FileUtils.split(path,path_pattern,3);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_spilt:
                //FileUtils.split();
                spilt();
                break;
            case R.id.btn_merge:
                //FileUtils.merge();
                break;
            default:
                break;
        }
    }
}
