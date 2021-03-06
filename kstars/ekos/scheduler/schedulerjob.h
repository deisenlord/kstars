/*  Ekos Scheduler Job
    Copyright (C) Jasem Mutlaq <mutlaqja@ikarustech.com>

    This application is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.
 */

#pragma once

#include "skypoint.h"

#include <QUrl>
#include <QMap>

class QTableWidgetItem;

class dms;

class SchedulerJob
{
  public:
    SchedulerJob();

    typedef enum {
        JOB_IDLE,
        JOB_EVALUATION,
        JOB_SCHEDULED,
        JOB_BUSY,
        JOB_ERROR,
        JOB_ABORTED,
        JOB_INVALID,
        JOB_COMPLETE
    } JOBStatus;
    typedef enum {
        STAGE_IDLE,
        STAGE_SLEWING,
        STAGE_SLEW_COMPLETE,
        STAGE_FOCUSING,
        STAGE_FOCUS_COMPLETE,
        STAGE_ALIGNING,
        STAGE_ALIGN_COMPLETE,
        STAGE_RESLEWING,
        STAGE_RESLEWING_COMPLETE,
        STAGE_POSTALIGN_FOCUSING,
        STAGE_POSTALIGN_FOCUSING_COMPLETE,
        STAGE_GUIDING,
        STAGE_GUIDING_COMPLETE,
        STAGE_CAPTURING,
        STAGE_COMPLETE
    } JOBStage;

    typedef enum { START_ASAP, START_CULMINATION, START_AT } StartupCondition;

    typedef enum { FINISH_SEQUENCE, FINISH_REPEAT, FINISH_LOOP, FINISH_AT } CompletionCondition;

    typedef enum {
        USE_NONE  = 0,
        USE_TRACK = 1 << 0,
        USE_FOCUS = 1 << 1,
        USE_ALIGN = 1 << 2,
        USE_GUIDE = 1 << 3
    } StepPipeline;

    SkyPoint const & getTargetCoords() const;
    void setTargetCoords(dms& ra, dms& dec);

    QUrl getSequenceFile() const;
    void setSequenceFile(const QUrl &value);

    QUrl getFITSFile() const;
    void setFITSFile(const QUrl &value);

    double getMinAltitude() const;
    void setMinAltitude(const double &value);

    double getMinMoonSeparation() const;
    void setMinMoonSeparation(const double &value);

    bool getEnforceWeather() const;
    void setEnforceWeather(bool value);

    StepPipeline getStepPipeline() const;
    void setStepPipeline(const StepPipeline &value);

    StartupCondition getStartupCondition() const;
    void setStartupCondition(const StartupCondition &value);

    CompletionCondition getCompletionCondition() const;
    void setCompletionCondition(const CompletionCondition &value);

    /** @brief Time after which the job is considered complete. */
    /** @{ */
    QDateTime getCompletionTime() const;
    void setCompletionTime(const QDateTime &value);
    /** @} */

    int16_t getCulminationOffset() const;
    void setCulminationOffset(const int16_t &value);

    void setDateTimeDisplayFormat(const QString &value);

    StartupCondition getFileStartupCondition() const;
    void setFileStartupCondition(const StartupCondition &value);

    bool getInSequenceFocus() const;
    void setInSequenceFocus(bool value);

    uint8_t getPriority() const;
    void setPriority(const uint8_t &value);

    bool getEnforceTwilight() const;
    void setEnforceTwilight(bool value);

    /** @brief Current name of the scheduler job. */
    /** @{ */
    QString getName() const { return name; }
    void setName(const QString &value);
    /** @} */

    /** @brief Shortcut to widget cell for job name in the job queue table. */
    /** @{ */
    QTableWidgetItem *getNameCell() const { return nameCell; }
    void setNameCell(QTableWidgetItem *cell);
    /** @} */

    /** @brief Current state of the scheduler job. */
    /** @{ */
    JOBStatus getState() const { return state; }
    void setState(const JOBStatus &value);
    /** @} */

    /** @brief Shortcut to widget cell for job state in the job queue table. */
    /** @{ */
    QTableWidgetItem *getStatusCell() const { return statusCell; }
    void setStatusCell(QTableWidgetItem *cell);
    /** @} */

    /** @brief Current stage of the scheduler job. */
    /** @{ */
    JOBStage getStage() const { return stage; }
    void setStage(const JOBStage &value);
    /** @} */

    /** @brief Shortcut to widget cell for job stage in the job queue table. */
    /** @{ */
    QTableWidgetItem *getStageCell() const { return stageCell; }
    void setStageCell(QTableWidgetItem *cell);
    /** @} */

    /** @brief Number of captures required in the associated sequence. */
    /** @{ */
    int getSequenceCount() const { return sequenceCount; }
    void setSequenceCount(const int count);
    /** @} */

    /** @brief Number of captures completed in the associated sequence. */
    /** @{ */
    int getCompletedCount() const { return completedCount; }
    void setCompletedCount(const int count);
    /** @} */

    /** @brief Shortcut to widget cell for captures in the job queue table. */
    /** @{ */
    QTableWidgetItem *getCaptureCountCell() const { return captureCountCell; }
    void setCaptureCountCell(QTableWidgetItem *value);
    /** @} */

    /** @brief Time at which the job must start. */
    /** @{ */
    QDateTime getStartupTime() const { return startupTime; }
    void setStartupTime(const QDateTime &value);
    /** @} */

    /** @brief Shortcut to widget cell for startup time in the job queue table. */
    /** @{ */
    QTableWidgetItem *getStartupCell() const { return startupCell; }
    void setStartupCell(QTableWidgetItem *value);
    /** @} */

    /** @brief Shortcut to widget cell for completion time in the job queue table. */
    /** @{ */
    QTableWidgetItem *getCompletionCell() const { return completionCell; }
    void setCompletionCell(QTableWidgetItem *value);
    /** @} */

    /** @brief Estimation of the time the job will take to process. */
    /** @{ */
     int64_t getEstimatedTime() const { return estimatedTime; }
    void setEstimatedTime(const int64_t &value);
    /** @} */

    /** @brief Shortcut to widget cell for estimated time in the job queue table. */
    /** @{ */
    QTableWidgetItem *getEstimatedTimeCell() const { return estimatedTimeCell; }
    void setEstimatedTimeCell(QTableWidgetItem *value);
    /** @} */

    /** @brief Current score of the scheduler job. */
    /** @{ */
    int getScore() const { return score; }
    void setScore(int value);
    /** @} */

    /** @brief Shortcut to widget cell for job score in the job queue table. */
    /** @{ */
    QTableWidgetItem *getScoreCell() const { return scoreCell; }
    void setScoreCell(QTableWidgetItem *value);
    /** @} */

    bool getLightFramesRequired() const;
    void setLightFramesRequired(bool value);

    uint16_t getRepeatsRequired() const;
    void setRepeatsRequired(const uint16_t &value);

    uint16_t getRepeatsRemaining() const;
    void setRepeatsRemaining(const uint16_t &value);

    QMap<QString, uint16_t> getCapturedFramesMap() const;
    void setCapturedFramesMap(const QMap<QString, uint16_t> &value);

    /** @brief Compare ::SchedulerJob instances based on score. This is a qSort predicate, deprecated in QT5.
     * @arg a, b are ::SchedulerJob instances to compare.
     * @return true if the score of b is lower than the score of a.
     * @return false if the score of b is higher than or equal to the score of a.
     */
    static bool decreasingScoreOrder(SchedulerJob const *a, SchedulerJob const *b);

    /** @brief Compare ::SchedulerJob instances based on priority. This is a qSort predicate, deprecated in QT5.
     * @arg a, b are ::SchedulerJob instances to compare.
     * @return true if the priority of a is lower than the priority of b.
     * @return false if the priority of a is higher than or equal to the priority of b.
     */
    static bool increasingPriorityOrder(SchedulerJob const *a, SchedulerJob const *b);

    /** @brief Compare ::SchedulerJob instances based on altitude. This is a qSort predicate, deprecated in QT5.
     * @arg a, b are ::SchedulerJob instances to compare.
     * @return true if the altitude of b is lower than the altitude of a.
     * @return false if the altitude of b is higher than or equal to the altitude of a.
     */
    static bool decreasingAltitudeOrder(SchedulerJob const *a, SchedulerJob const *b);

private:
    QString name;
    SkyPoint targetCoords;
    JOBStatus state { JOB_IDLE };
    JOBStage stage { STAGE_IDLE };

    StartupCondition fileStartupCondition { START_ASAP };
    StartupCondition startupCondition { START_ASAP };
    CompletionCondition completionCondition { FINISH_SEQUENCE };

    int sequenceCount { 0 };
    int completedCount { 0 };

    QDateTime startupTime;
    QDateTime completionTime;

    QUrl sequenceFile;
    QUrl fitsFile;

    double minAltitude { -1 };
    double minMoonSeparation { -1 };

    bool enforceWeather { false };
    bool enforceTwilight { false };

    StepPipeline stepPipeline { USE_NONE };

    /** @internal Widget cell shortcuts. */
    /** @{ */
    QTableWidgetItem *nameCell { nullptr };
    QTableWidgetItem *statusCell { nullptr };
    QTableWidgetItem *stageCell { nullptr };
    QTableWidgetItem *startupCell { nullptr };
    QTableWidgetItem *completionCell { nullptr };
    QTableWidgetItem *estimatedTimeCell { nullptr };
    QTableWidgetItem *captureCountCell { nullptr };
    QTableWidgetItem *scoreCell { nullptr };
    /** @} */

    /** @internal General cell refresh. */
    void updateJobCell();

    int score { 0 };
    int16_t culminationOffset { 0 };
    uint8_t priority { 10 };
    int64_t estimatedTime { -1 };
    uint16_t repeatsRequired { 0 };
    uint16_t repeatsRemaining { 0 };
    bool inSequenceFocus { false };

    QString dateTimeDisplayFormat;

    bool lightFramesRequired { false };

    QMap<QString, uint16_t> capturedFramesMap;
};
