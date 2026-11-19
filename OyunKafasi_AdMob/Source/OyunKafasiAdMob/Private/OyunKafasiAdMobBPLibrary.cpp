#include "OyunKafasiAdMobBPLibrary.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

void UOyunKafasiAdMobBPLibrary::InitAdMob(FString AdUnitID)
{
#if PLATFORM_ANDROID
    if (AdUnitID.IsEmpty())
    {
        return;
    }

    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        static jmethodID Method = FJavaWrapper::FindMethod(
            Env,
            FJavaWrapper::GameActivityClassID,
            "AndroidThunkJava_InitAdMob",
            "(Ljava/lang/String;)V",
            false
        );

        if (Method)
        {
            jstring JAdUnitID = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
            FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method, JAdUnitID);
            Env->DeleteLocalRef(JAdUnitID);
        }
    }
#endif
}

bool UOyunKafasiAdMobBPLibrary::IsInterstitialAdReady()
{
#if PLATFORM_ANDROID
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        static jmethodID Method = FJavaWrapper::FindMethod(
            Env,
            FJavaWrapper::GameActivityClassID,
            "AndroidThunkJava_IsInterstitialReady",
            "()Z",
            false
        );

        if (Method)
        {
            return FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GameActivityThis, Method);
        }
    }
#endif

    return false;
}

void UOyunKafasiAdMobBPLibrary::ShowInterstitialAd()
{
#if PLATFORM_ANDROID
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        static jmethodID Method = FJavaWrapper::FindMethod(
            Env,
            FJavaWrapper::GameActivityClassID,
            "AndroidThunkJava_ShowInterstitial",
            "()V",
            false
        );

        if (Method)
        {
            FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, Method);
        }
    }
#endif
}
