cmake_minimum_required(VERSION 3.1)
if (CMAKE_VERSION VERSION_LESS "3.7.0")
	set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

project(QDiscord VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Runs Qt stuff
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Dependencies
find_package(Qt5 COMPONENTS Core Gui Network WebSockets Widgets)

# Files
set(HEADERS
	Discord.h

	Discord/Client.h Discord/GatewayEvents.h Discord/GatewaySocket.h Discord/HttpService.h
	Discord/Payload.h Discord/Promise.h Discord/Token.h Discord/Url.h

	Discord/Objects/Activity.h Discord/Objects/Attachment.h Discord/Objects/Ban.h Discord/Objects/Channel.h
	Discord/Objects/Connection.h Discord/Objects/Embed.h Discord/Objects/Emoji.h Discord/Objects/Guild.h
	Discord/Objects/GuildEmbed.h Discord/Objects/GuildMember.h Discord/Objects/Integration.h Discord/Objects/Invite.h
	Discord/Objects/Message.h Discord/Objects/Overwrite.h Discord/Objects/PresenceUpdate.h Discord/Objects/Reaction.h
	Discord/Objects/Role.h Discord/Objects/User.h Discord/Objects/VoiceRegion.h Discord/Objects/VoiceState.h
	Discord/Objects/Webhook.h 

	Discord/Patches/Patch.h Discord/Patches/ChannelPatch.h Discord/Patches/EmojiPatch.h Discord/Patches/GuildEmbedPatch.h
	Discord/Patches/GuildMemberPatch.h Discord/Patches/GuildPatch.h Discord/Patches/IntegrationPatch.h
	Discord/Patches/MessagePatch.h Discord/Patches/RolePatch.h Discord/Patches/UserPatch.h Discord/Patches/WebhookPatch.h
)
set(SOURCES
	Discord/Client.cpp Discord/GatewayEvents.cpp Discord/GatewaySocket.cpp
	Discord/HttpService.cpp Discord/Token.cpp Discord/Url.cpp

	Discord/Objects/Activity.cpp Discord/Objects/Attachment.cpp Discord/Objects/Ban.cpp Discord/Objects/Channel.cpp
	Discord/Objects/Connection.cpp Discord/Objects/Embed.cpp Discord/Objects/Emoji.cpp Discord/Objects/Guild.cpp
	Discord/Objects/GuildEmbed.cpp Discord/Objects/GuildMember.cpp Discord/Objects/Integration.cpp Discord/Objects/Invite.cpp
	Discord/Objects/Message.cpp Discord/Objects/Overwrite.cpp Discord/Objects/PresenceUpdate.cpp Discord/Objects/Reaction.cpp
	Discord/Objects/Role.cpp Discord/Objects/User.cpp Discord/Objects/VoiceRegion.cpp Discord/Objects/VoiceState.cpp
	Discord/Objects/Webhook.cpp 

	Discord/Patches/ChannelPatch.cpp Discord/Patches/EmojiPatch.cpp Discord/Patches/GuildEmbedPatch.cpp
	Discord/Patches/GuildMemberPatch.cpp Discord/Patches/GuildPatch.cpp Discord/Patches/IntegrationPatch.cpp
	Discord/Patches/MessagePatch.cpp Discord/Patches/RolePatch.cpp Discord/Patches/UserPatch.cpp Discord/Patches/WebhookPatch.cpp
)
list(TRANSFORM HEADERS PREPEND src/core/)
list(TRANSFORM SOURCES PREPEND src/core/)

# The library
add_library(QDiscord ${HEADERS} ${SOURCES})
target_link_libraries(QDiscord Qt5::Core Qt5::Gui Qt5::Network Qt5::WebSockets Qt5::Widgets)
target_include_directories(QDiscord PUBLIC src/core/)
