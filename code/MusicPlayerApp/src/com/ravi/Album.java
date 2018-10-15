package com.ravi;

import java.util.ArrayList;

public class Album {
    private String name;
    private ArrayList<Song> Albums;
    public Album(String name) {
        this.name = name;
        Albums = new ArrayList<Song>(){};
    }
    public ArrayList<Song> getAlbums() {
        return Albums;
    }

    public void AddSong(Song song) {
        Albums.add(song);
    }
    public boolean findSong(String name){
        for(int i=0;i<Albums.size();i++){
            if(Albums.get(i).getTitle().equals(name)){
                return true;
            }
        }
        return false;
    }

}
