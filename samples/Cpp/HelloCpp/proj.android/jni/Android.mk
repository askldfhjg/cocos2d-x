LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hellocpp_shared

LOCAL_MODULE_FILENAME := libhellocpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
				   ../../Classes/BoneAction/CCLayerAction.cpp	\
                   ../../Classes/BoneAction/CCBone.cpp \
                   ../../Classes/BoneAction/CCBoneActionManager.cpp \
                    ../../Classes/BoneAction/CCBoneTextureManager.cpp \
                   ../../Classes/BoneAction/CCBoneSpriteLayer.cpp \
                   ../../Classes/BoneAction/function.cpp \
                   ../../Classes/FightScene.cpp \
                   ../../Classes/LoadingScene.cpp \
                   ../../Classes/TableViewTestScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes \
			$(LOCAL_PATH)/../../../../../extensions

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)

