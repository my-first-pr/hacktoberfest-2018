package com.ravi;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class Main {
    private static LinkedList<Song> playlist = new LinkedList<Song>();
    private static Scanner sc = new Scanner(System.in);
    private static Album album =new Album("favourite");
    private static Song currentSong = null;
    public static void main(String[] args) {
        int choice;
        boolean control = true;
	  while(control){
          System.out.println("press 1 for menu ");
          choice = sc.nextInt();
          sc.nextLine();
          switch (choice){
              case 1:
                  printMenu();
                  break;
              case 2:
                  AddToAlbum();
                  break;
              case 3:
                  AddToPlayList();
                  break;
              case 4:
                  AlbumList();
                  break;
              case 5:
                  ViewPlayList();
                  break;
              case 6:
                  playSong();
                  break;
              case 7:
                  NextSong();
                  break;
              case 8:
                  PreviousSong();
                  break;
              case 9:
                  Replay();
                  break;
              case 10:
                  RemoveSong();
                  break;
              case 11:
                  control = false;
                  break;
          }

      }
    }
    private static void printMenu(){
        System.out.println("1.Menu\n" + "2.Add song to album\n" + "3.Add song to playlist\n" + "4.List the song in album\n"
        + "5.List of the song in playlist \n" + "6.Play song" + "7.Next song\n" + "8.Previous Song\n" + "9.Replay the song\n"
                + "10.Remove the song\n" + "11.Quit");
    }
    private static void AddToAlbum(){
        System.out.println("Enter the name of the song");
        String name = sc.nextLine();
        System.out.println("Enter the duration of the song in minutes");
        double duration = sc.nextDouble();
        Song song = new Song(name,duration);
        album.AddSong(song);
        System.out.println("Your song is added is successful");
    }
    private static void AddToPlayList(){
        System.out.println("Enter the name of the song");
        String name = sc.nextLine();
        System.out.println("Enter the duration of the song in minutes");
        double duration = sc.nextDouble();
        if(album.findSong(name)){
            Song song = new Song(name,duration);
            playlist.add(song);
            System.out.println("Your song is added successfully.");
        }
        else{
            System.out.println("The song doesn't exists in the albums.");
        }
    }
    private static void AlbumList(){
        ArrayList<Song> albumList = album.getAlbums();
        for(int i=0;i< albumList.size();i++){
            System.out.println(i+1 + ". " + albumList.get(i).getTitle());
        }
    }
    private static void ViewPlayList(){
        ListIterator<Song> songList = playlist.listIterator();//Initially it is not pointing to any element.
        int i=1;
        while(songList.hasNext()){
            System.out.println(i + ". " + songList.next().getTitle());
            i++;
        }
    }
    private static void playSong(){
        System.out.println("Enter the name of the song you want to play.");
       ListIterator<Song> songList = playlist.listIterator();
        String name = sc.nextLine();
        while(songList.hasNext()){
            if(songList.next().getTitle().equals(name)){
                currentSong = songList.previous();
                System.out.println("Now Playing : " + name);
                return;
            }
        }
        System.out.println("The song doesn't exists");
    }
    private static void NextSong(){
        ListIterator<Song> songList = playlist.listIterator();
        if(currentSong!=null) {
            while (songList.hasNext()) {
                if (songList.next().getTitle().equals(currentSong.getTitle())) {
                    Song song = songList.next();
                    System.out.println("Now Playing : " + song.getTitle() + " " + song.getDuration() + "min");
                    currentSong = songList.previous();
                    return;
                }
            }
        }
        System.out.println("Now Playing : " + songList.next().getTitle());
    }
    private static void PreviousSong(){
        ListIterator<Song> songList = playlist.listIterator();
        if(currentSong!=null) {
            while (songList.hasNext()) {
                if (songList.next().getTitle().equals(currentSong.getTitle())) {
                    songList.previous();
                    Song song = songList.previous();
                    System.out.println("Now Playing : " + song.getTitle() + " " + song.getDuration() + "min");
                    currentSong = songList.next();
                    return;
                }
            }
        }
        System.out.println("We are at the starting of the list");
    }
    private static void Replay(){
        System.out.println("Now Playing : " + currentSong.getTitle() + " " + currentSong.getDuration() + "min");
    }
    private static void RemoveSong(){
        System.out.println("Enter the name of the song you want to remove.");
        ListIterator<Song> songList = playlist.listIterator();
        String name = sc.nextLine();
        while(songList.hasNext()){
            if(songList.next().getTitle().equals(name)){
                playlist.remove(songList.previous());
                System.out.println("Your song is removed successfully");
                return;
            }
        }
        System.out.println("Song does not exists.");
    }
}
