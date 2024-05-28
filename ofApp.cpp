#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255, 64);

	ofNoFill();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int x = -230; x <= 230; x += 230) {

		for (int y = -230; y <= 230; y += 230) {

			glm::vec3 noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
			for (int i = 0; i < 15; i++) {

				ofColor color;
				color.setHsb(ofMap(i % 5, 0, 5, 0, 255), 200, 255);
				ofSetColor(color);

				ofPushMatrix();
				ofTranslate(x, y);

				ofRotateZ(ofMap(ofNoise(noise_seed.x, ofGetFrameNum() * 0.0085), 0, 1, -180, 180) + i * 5);
				ofRotateY(ofMap(ofNoise(noise_seed.x, ofGetFrameNum() * 0.0085), 0, 1, -180, 180) + i * 5);
				ofRotateX(ofMap(ofNoise(noise_seed.x, ofGetFrameNum() * 0.0085), 0, 1, -180, 180) + i * 5);

				ofDrawRectangle(glm::vec2(), 120, 120);

				ofPopMatrix();
			}
		}
	}

	/*
	int start = 160;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}