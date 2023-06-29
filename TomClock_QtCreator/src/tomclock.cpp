#include "tomclock.h"

TomClock::TomClock()
{



    tcDatabase = new TomClockDatabase();
    tcDatabase->queryMission(missionList);
    tcDatabase->queryHistory(historyList);
//    achievementW = new AchievementWindow();
    createW = new CreateMissionWindow();
    missionListW = new MissionListWindow(missionList);
    historyW=new HistoryWindow();
    runW = new RunWindow();
    settingW = new Settings();
    aboutW = new about();
    teamW = new OurTeam();

    //achieve test
    Achievement a1("第1个番茄", 0, "获得你的第1个番茄");
    Achievement a2("第5个番茄", 0, "累计获得5个番茄");
    Achievement a3("第10个番茄", 0, "累计获得10个番茄");
    Achievement a4("第100个番茄", 0, "累计获得100个番茄");
    Achievement a5("第150个番茄", 0, "累计获得150个番茄");
    achieveList.append(a1);
    achieveList.append(a2);
    achieveList.append(a3);
    achieveList.append(a4);
    achieveList.append(a5);
    a1.setState(1);
    tcDatabase->updateAchievement(a1);
    //achieve test end

    initAchieveWindow();


    mainW = new MainWindow(historyList);

    qRegisterMetaType<QVector<History>>("QVector<History>");



   // missionListW->initMissions(missionList);
    //各页面之间进行跳转的实现
    connect(mainW, SIGNAL(JumptoAchievement()), achievementW, SLOT(MaintoAchievement()));
    connect(mainW, SIGNAL(JumptoHistory( QVector<History>)), historyW, SLOT(MaintoHistory( QVector<History>)));
//    connect(&mainW, SIGNAL(JumptoMissionCreate()), &createW, SLOT(MaintoCreate()));
    connect(mainW, SIGNAL(JumptoMissionList()), missionListW, SLOT(MaintoList()));
    connect(mainW, SIGNAL(JumptoSettings()), settingW, SLOT(MaintoSettings()));
    connect(mainW, SIGNAL(JumptoAbout()), aboutW, SLOT(MaintoAbout()));

    connect(historyW, SIGNAL(BacktoMain()), mainW, SLOT(HistorytoMain()));

    connect(aboutW, SIGNAL(AbouttoTeam()), teamW, SLOT(AbouttoTeam()));
    connect(aboutW, SIGNAL(BacktoMain()), mainW, SLOT(AbouttoMain()));

    connect(missionListW,SIGNAL(jumpToRunWindows(Mission)),runW,SLOT(ListtoRun(Mission)));
    connect(missionListW,SIGNAL(create()),createW,SLOT(toCreate()));
    connect(missionListW, SIGNAL(BacktoMain()), mainW, SLOT(ListtoMain()));

    connect(teamW, SIGNAL(BacktoAbout()), aboutW, SLOT(TeamtoAbout()));
    connect(settingW, SIGNAL(BacktoMain()), mainW, SLOT(SettingstoMain()));
    connect(runW, SIGNAL(JumptoMain()), mainW, SLOT(RuntoMain()));
    connect(achievementW, SIGNAL(JumptoMain()), mainW, SLOT(AchievetoMain()));
    //    connect(&createW,SIGNAL(sentAndJump(Mission)),&mainW,SLOT(othertoMain()));
    connect(createW,SIGNAL(sentAndJump(Mission)),missionListW,SLOT(recieveMission(Mission)));
    connect(missionListW,SIGNAL(updateDatabase()),this,SLOT(updataMissionDatabase()));
    connect(runW,SIGNAL(sentHistory(History )),this,SLOT(updataHistoryDatabase(History)));
}

TomClock::~TomClock()
{
    delete tcDatabase;
    delete mainW;
    delete achievementW;
    delete createW;
    delete historyW;
    delete missionListW;
    delete runW;
    delete settingW;
    delete aboutW;
    delete teamW;
}

void TomClock::initAchieveWindow()
{
    tcDatabase->initAchievement(achieveList);       //若表为空则初始化，否则不做操作
    tcDatabase->queryAchievement(achieveList);      //从数据库获取成就数据
    achievementW = new AchievementWindow(achieveList);
}

void TomClock::initMissionListWindow()
{
    tcDatabase->queryMission(missionList);
    //将missionList传给missionListW
}



void TomClock::showWindow()
{
    mainW->show();
}

void TomClock::updataMissionDatabase(){
    missionList.clear();
    missionList=missionListW->getMission();
    qDebug()<<"hhhhhh";
    tcDatabase->updateMission(missionList);
}

void TomClock::updataHistoryDatabase(History h){
    h.setId(historyList.size());
    historyList.push_back(h);
    tcDatabase->addHistory(h);
}
