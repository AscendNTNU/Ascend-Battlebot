pipeline {
  agent any
  stages {
    stage('checkout')  {
      steps {
        checkout scm
        sh 'git submodule update --init --recursive'
      }
    }
    stage('build-docker')  {
      steps {
        sh 'docker build -t rendell/ascend-battlebot .'
      }
    }
    stage('build') {
      steps {
        sh 'docker run rendell/ascend-battlebot'
      }
    }
  }
  post {
    cleanup {
      cleanWs()
    }
  }
}
