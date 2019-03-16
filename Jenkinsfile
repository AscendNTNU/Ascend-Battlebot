pipeline {
  agent any
  stages {
    stage('checkout')  {
      steps {
        checkout scm
      }
    }
    stage('build-docker')  {
      steps {
        sh 'docker build -t Ascend-Battlebot .'
      }
    }
    stage('build') {
      steps {
        sh 'docker run Ascend-Battlebot make'
      }
    }
  }
  post {
    cleanup {
      cleanWs()
    }
  }
}
