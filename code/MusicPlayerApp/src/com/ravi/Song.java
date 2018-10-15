package com.ravi;


public class Song {
    private String title;
    private double duration;
    public Song(String title, double duration) {
        this.title = title;
        this.duration = duration;
    }

    public String getTitle() {
        return title;
    }

    public double getDuration() {
        return duration;
    }
}
