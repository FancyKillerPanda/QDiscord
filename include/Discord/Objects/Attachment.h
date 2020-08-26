/*
 * Copyright (c) 2020 Sebastian Kylander https://gaztin.com/
 *
 * This software is provided 'as-is', without any express or implied warranty. In no event will
 * the authors be held liable for any damages arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose, including commercial
 * applications, and to alter it and redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not claim that you wrote the
 *    original software. If you use this software in a product, an acknowledgment in the product
 *    documentation would be appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be misrepresented as
 *    being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

#pragma once
#include "Discord.h"

#include <QtCore/QString>

class QJsonObject;

QDISCORD_NAMESPACE_BEGIN

class Attachment
{
public:
	explicit Attachment(const QJsonObject& data);

	const QString& filename() const { return filename_; }
	const QString& url() const { return url_; }
	const QString& proxyUrl() const { return proxy_url_; }
	snowflake_t id() const { return id_; }
	int size() const { return size_; }
	int height() const { return height_; }
	int width() const { return width_; }

private:
	QString filename_;
	QString url_;
	QString proxy_url_;

	snowflake_t id_;
	
	int size_;
	int height_;
	int width_;
};

QDISCORD_NAMESPACE_END
