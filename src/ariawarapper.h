#ifndef ARIAWARAPPER_H
#define ARIAWARAPPER_H
#include<aria2/aria2.h>
#include <QObject>
#include<iostream>
#include<chrono>

int downloadEventCallback(aria2::Session* session, aria2::DownloadEvent event, const aria2::A2Gid gid, void* userData);

class ariawarapper : public QObject
{
    Q_OBJECT
public:
    explicit ariawarapper(QObject *parent=0);
    aria2::Session* session;
    aria2::SessionConfig config;
    aria2::KeyVals options;
    aria2::GlobalStat gstat;

signals:
    void globalDownloadStat(int inactive, int active, int gdl, int gup);
    void downloadStatPerItem(uint id, int completed, int total,int perDl, int perUp);
    void finishAddNew(uint fid);

public slots:
    void update();
    void addNewDownload(QString url, QString location);

private:

};

#endif // ARIAWARAPPER_H
