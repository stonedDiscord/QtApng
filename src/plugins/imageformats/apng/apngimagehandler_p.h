#ifndef APNGIMAGEHANDLER_P_H
#define APNGIMAGEHANDLER_P_H

#include <QImageIOHandler>
#include <QVariant>
#include <QImage>
#include <QVector>
class ApngReader;

class ApngImageHandler : public QImageIOHandler
{
	Q_DISABLE_COPY(ApngImageHandler)
public:
	ApngImageHandler();
	~ApngImageHandler() override;

	// QImageIOHandler interface
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	QByteArray name() const override;
#else
    QByteArray name() const;
#endif
bool canRead() const final;
	bool read(QImage *image) final;
	QVariant option(ImageOption option) const final;
	bool supportsOption(ImageOption option) const final;
	bool jumpToNextImage() final;
	bool jumpToImage(int imageNumber) final;
	int loopCount() const final;
	int imageCount() const final;
	int nextImageDelay() const final;
	int currentImageNumber() const final;

private:
	quint32 _index = 0;
	QScopedPointer<ApngReader> _reader;
};

#endif // APNGIMAGEHANDLER_P_H
