package com.example.wushufeng.ndk_demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.support.v7.widget.AppCompatButton;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class LoginActivity extends AppCompatActivity implements View.OnClickListener {

    static {
        System.loadLibrary("login");
        System.loadLibrary("loginCallJavaMethod");
    }

    private EditText name;
    private EditText password;
    private String strNameNotExist ="用户名不存在!";
    private String strPasswordError ="密码错误";
    private String strLoginSuccess ="登录成功!";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);
        AppCompatButton btnLoginTest = findViewById(R.id.btn_login_test);
        btnLoginTest.setOnClickListener(this);
        name = findViewById(R.id.et_name);
        password = findViewById(R.id.et_password);
    }

    public native String login(String name, String password, int authcode);
    public native void loginsuccess(String name, String password, int authcode);

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_login_test:
                //Toast.makeText(this, this.login(name.getText().toString(), password.getText().toString(), 888), Toast.LENGTH_SHORT).show();
                this.loginsuccess(name.getText().toString(), password.getText().toString(), 888);
                break;
            default:
                break;
        }
    }

    void showToast(String str){
        Toast.makeText(this, str, Toast.LENGTH_SHORT).show();
    }
}
