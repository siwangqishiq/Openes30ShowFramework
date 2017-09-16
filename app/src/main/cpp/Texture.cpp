//
// Created by panyi on 2017/9/15.
//

#include "Texture.h"
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

int TextureInstance::init() {
    char vShaderStr[] =
            "#version 300 es    \n"
                    "layout(location = 0) in vec4 a_position; \n"
                    "layout(location = 1) in vec2 a_texCoord; \n"
                    "out vec2 v_texCoord; \n"
                    "void main()    \n"
                    "{              \n"
                    "   gl_Position = a_position; \n"
                    "   v_texCoord = a_texCoord; \n"
                    "}              \n";

    char fShaderStr[] =
            "#version 300 es    \n"
                    "precision mediump float; \n"
                    "in vec2 v_texCoord; \n"
                    "layout(location = 0) out vec4 outColor; \n"
                    "uniform sampler2D s_texture; \n"
                    "void main() { \n"
                    "   outColor = texture(s_texture , v_texCoord); \n"
                    "}  \n";

    this->m_program = loadProgram(vShaderStr, fShaderStr);
    if (m_program == GL_FALSE) {
        ALOGE("%s", "load progream Error!");
        return GL_FALSE;
    }

    this->m_texture_id = createSimpleTexture2D();
    this->m_sampler_loc = glGetUniformLocation(this->m_program , "s_texture");


    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    return GL_TRUE;
}

GLboolean  loadTexture(){

}

GLuint TextureInstance::createSimpleTexture2D() {
    GLuint textureId;
    GLubyte pixels[4 * 3] = {
            255, 0, 0,
            0, 255, 0,
            0, 0, 255,
            255, 255, 0
    };

    // Use tightly packed data
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    // Generate a texture object
    glGenTextures(1, &textureId);

    // Bind the texture object
    glBindTexture(GL_TEXTURE_2D, textureId);

    // Load the texture
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    // Set the filtering mode
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D , 0);
    return textureId;
}


void TextureInstance::resize(int w, int h) {
    this->m_width = w;
    this->m_height = h;
}

void TextureInstance::update() {
    //ALOGE("HelloTrigle::update");
    GLfloat vVertices[] = {
            -0.5f, 0.5f, 0.0f,  // Position 0
            0.0f, 0.0f,        // TexCoord 0
            -0.5f, -0.5f, 0.0f,  // Position 1
            0.0f, 1.0f,        // TexCoord 1
            0.5f, -0.5f, 0.0f,  // Position 2
            1.0f, 1.0f,        // TexCoord 2
//            0.5f, 0.5f, 0.0f,  // Position 3
//            1.0f, 0.0f         // TexCoord 3
    };
    GLushort indices[] = { 0, 1, 2};

    glViewport(0, 0, this->m_width, this->m_height);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(this->m_program);

    glVertexAttribPointer(0, 3, GL_FLOAT,
                            GL_FALSE, 5 * sizeof ( GLfloat ), vVertices );//设置顶点位置坐标数据
    glVertexAttribPointer ( 1, 2, GL_FLOAT,
                            GL_FALSE, 5 * sizeof ( GLfloat ), &vVertices[3] );//设置顶点纹理坐标数据
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture( GL_TEXTURE_2D, m_texture_id);
    // Set the sampler texture unit to 0
    glUniform1i(m_sampler_loc, 0);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT,indices);

    GLfloat vVertices2[] = {
            -0.5f, 0.5f, 0.0f,  // Position 0
            0.0f, 0.0f,        // TexCoord 0
            0.5f, -0.5f, 0.0f,  // Position 1
            1.0f, 1.0f,        // TexCoord 1
            0.5f, 0.5f, 0.0f,  // Position 2
            1.0f, 0.0f         // TexCoord 2
    };
    GLushort indices2[] = { 0, 1, 2};
    glVertexAttribPointer(0, 3, GL_FLOAT,
                          GL_FALSE, 5 * sizeof ( GLfloat ), vVertices2);//设置顶点位置坐标数据
    glVertexAttribPointer ( 1, 2, GL_FLOAT,
                            GL_FALSE, 5 * sizeof ( GLfloat ), &vVertices2[3] );//设置顶点纹理坐标数据
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT,indices2);
}

void TextureInstance::destory() {
    ALOGE("HelloTrigle::destory");
    glDeleteTextures(1, &m_texture_id);
    if (m_program > 0) {
        glDeleteProgram(this->m_program);
    }
}

int TextureImage::init() {
    char vShaderStr[] =
            "#version 300 es    \n"
                    "layout(location = 0) in vec4 a_position; \n"
                    "layout(location = 1) in vec2 a_texCoord; \n"
                    "out vec2 v_texCoord; \n"
                    "void main()    \n"
                    "{              \n"
                    "   gl_Position = a_position; \n"
                    "   v_texCoord = a_texCoord; \n"
                    "}              \n";

    char fShaderStr[] =
            "#version 300 es    \n"
                    "precision mediump float; \n"
                    "in vec2 v_texCoord; \n"
                    "layout(location = 0) out vec4 outColor; \n"
                    "uniform sampler2D s_texture; \n"
                    "void main() { \n"
                    "   outColor = texture(s_texture , v_texCoord); \n"
                    "}  \n";

    this->m_program = loadProgram(vShaderStr, fShaderStr);
    if (m_program == GL_FALSE) {
        ALOGE("%s", "load progream Error!");
        return GL_FALSE;
    }

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    return GL_TRUE;
}

void TextureImage::resize(int w, int h) {
    this->m_width = w;
    this->m_height = h;
}

void TextureImage::update() {
    glViewport(0, 0, this->m_width, this->m_height);
    glClear(GL_COLOR_BUFFER_BIT);
}

void TextureImage::destory() {
    if (m_program > 0) {
        glDeleteProgram(this->m_program);
    }
}




