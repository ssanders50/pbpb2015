from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'HydjetMB_AOD_750pre5'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.psetName = '/home/sanders/aod_75x/HiEvtPlaneFlatten/HiEvtPlaneFlatCalib/hievtplaneflatcalib_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.outputFiles = ['rpflat.root']
config.JobType.maxJobRuntimeMin = 1315
#config.JobType.inputFiles = ['HeavyIonRPRcd_Hydjet_74x_v02_mc.db']

config.Data.inputDataset = '/Hydjet_Quenched_MinBias_5020GeV/tuos-HydjetMB_AOD_750pre5_round3v01-81dd8ce0064b5342f0d7e3ef953b6d47/USER'
config.Data.unitsPerJob = 10
config.Data.publication = False
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'LumiBased'
config.Data.outLFNDirBase = '/store/user/ssanders/75X'
config.Site.whitelist = ['T2_US_Vanderbilt']
config.Site.storageSite = 'T2_US_Vanderbilt'
