#ifndef SMOOTHINGFILTER_H
#define SMOOTHINGFILTER_H

#include <QtGui>
#include "volumefilemanager.h"
#include "propertyeditor.h"
#include "cropobject.h"
#include "pathobject.h"

#include <QGLViewer/vec.h>
using namespace qglviewer;

class VEDFilter
{
 public :
  VEDFilter();
  ~VEDFilter();

  QString start(VolumeFileManager*,
		int, int, int,
		Vec, Vec,
		QString,
		Vec,
		QList<Vec>,
		QList<Vec>,
		QList<CropObject>,
		QList<PathObject>,
		uchar*,
		int, int, int, int,
		QVector<uchar>);

 private :
  QTextEdit *m_meshLog;
  QProgressBar *m_meshProgress;

  VolumeFileManager *m_vfm;
  int m_voxelType;
  int m_nX, m_nY, m_nZ;
  int m_depth, m_width, m_height;
  Vec m_dataMin, m_dataMax, m_dataSize;

  bool m_blendPresent;
  bool m_tearPresent;
  bool m_cropPresent;
  bool m_pathBlendPresent;
  bool m_pathCropPresent;
  QList<CropObject> m_crops;
  QList<PathObject> m_paths;

  int m_pruneX, m_pruneY, m_pruneZ;
  float m_pruneLod;
  QVector<uchar> m_pruneData;

  void applyFilter(QString,
		   Vec,
		   QList<Vec>,
		   QList<Vec>,
		   QList<CropObject>,
		   QList<PathObject>,
		   uchar*,
		   int,
		   float, float, int, int,
		   bool);

  bool checkPathCrop(Vec);
  bool checkPathBlend(Vec, ushort, uchar*);
  bool checkCrop(Vec);
  bool checkBlend(Vec, ushort, uchar*);

  void savePvl(QString);

  int m_niter;
  int m_prog;
  void next();
};

#endif
