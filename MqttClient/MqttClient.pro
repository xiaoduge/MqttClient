#-------------------------------------------------
#
# Project created by QtCreator 2019-05-30T09:22:34
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = MqttClient
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    mqtt.c \
    MQTTUnsubscribeServer.c \
    MQTTUnsubscribeClient.c \
    MQTTSubscribeServer.c \
    MQTTSubscribeClient.c \
    MQTTSerializePublish.c \
    MQTTPacket.c \
    MQTTLinux.c \
    MQTTFormat.c \
    MQTTDeserializePublish.c \
    MQTTConnectServer.c \
    MQTTConnectClient.c \
    MQTTClient.c \
    dmqttclient.cpp

HEADERS += \
    mqtt.h \
    StackTrace.h \
    MQTTUnsubscribe.h \
    MQTTSubscribe.h \
    MQTTPublish.h \
    MQTTPacket.h \
    MQTTLinux.h \
    MQTTFormat.h \
    MQTTConnect.h \
    MQTTClient.h \
    dmqttclient.h
