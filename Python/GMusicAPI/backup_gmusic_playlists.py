import time
import xml.etree.ElementTree as ET
from gmusicapi import Mobileclient
"""
Saves all user-created Google Play Music playlists as an XML file.
"""
username = "jxile13@gmail.com"
password = "ywryyyvuwrdzycmd"
android_id= "3b91927c49923bf1"
def getMobileclient():
    api = Mobileclient()
    api.login(username, password, android_id)
    return api
def saveAllPlaylists():
    api = getMobileclient()
    if not api.is_authenticated():
        print("Sorry, those credentials weren't accepted")
        return
    print("Successfully logged in")
    playlists = api.get_all_user_playlist_contents()
    print("Playlists loaded")
    root = ET.Element("playlists")
    allSongs = api.get_all_songs()
    for playlist in playlists:
        playlistElement = ET.SubElement(root, "playlist")
        playlistElement.set("id", playlist["id"])
        playlistElement.set("name", playlist["name"])
        songs = playlist["tracks"]
        print("Found playlist '" + playlist["name"] + "' with" , len(songs) , "songs.")
        for song in songs:
            if not "track" in song:
                track = [songTemp for songTemp in allSongs if songTemp["id"] == song["trackId"]][0]
            else:
                track = song["track"]
            songElement = ET.SubElement(playlistElement, "song")
            songElement.set("id", song["id"])
            title = ET.SubElement(songElement, "title")
            title.text = track["title"]
            artist = ET.SubElement(songElement, "artist")
            artist.text = track["artist"]
            album = ET.SubElement(songElement, "album")
            album.text = track["album"]
    saveXML(root)
    print("Backup saved")
def saveXML(node):
    tree = ET.ElementTree(node)
    tree.write("gmusic backup " + getCurrentDate() + ".xml")
def getCurrentDate():
    return time.strftime("%Y-%m-%d")
if __name__ == '__main__':
    saveAllPlaylists()