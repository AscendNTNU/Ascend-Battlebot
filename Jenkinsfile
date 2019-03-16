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
        sh 'docker build -t rendell/ascend-battlebot .'
      }
    }
    stage('build') {
      steps {
        sh 'docker run rendell/ascend-battlebot make'
      }
    }
  }
  post {
    cleanup {
      cleanWs()
    }
  }
}
